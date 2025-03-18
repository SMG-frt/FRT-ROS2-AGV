import rclpy
from rclpy.node import Node
import evdev
from evdev import ecodes
from geometry_msgs.msg import Twist
from can_msgs.msg import Frame
import threading
import select

class JoystickTeleop(Node):
    def __init__(self):
        super().__init__('joystick_teleop')
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.can_publisher = self.create_publisher(Frame, 'can_data', 10) 
        
        self.device_path = self.find_joystick_device("NEOCON")
        if self.device_path is None:
            self.get_logger().error("NEOCON 조이스틱을 찾을 수 없습니다.")
            raise RuntimeError("NEOCON 조이스틱이 연결되지 않음")

        self.device = evdev.InputDevice(self.device_path)
        self.running = True
        self.active = False  # 조이스틱 입력 활성화 여부 (기본값: 비활성화)
        self.speed, self.turn = 0.5, 1.0
        self.linear_speed, self.angular_speed = 0.0, 0.0

        self.timer = self.create_timer(0.1, self.timer_callback)

        self.thread = threading.Thread(target=self.run)
        self.thread.start()

    def find_joystick_device(self, target_name):
        devices = [evdev.InputDevice(path) for path in evdev.list_devices()]
        for device in devices:
            if target_name in device.name:
                self.get_logger().info(f"조이스틱 찾음: {device.name} ({device.path})")
                return device.path
        return None

    def send_can_message(self, node_id, data):
        msg = Frame(id=node_id, dlc=len(data), is_extended=False, data=bytearray(data))
        self.can_publisher.publish(msg)

    def send_start_messages(self):
        can_messages = [
            [0x22, 0x40, 0x60, 0x00, 0x06, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x07, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x0F, 0x00, 0x00, 0x00]
        ]
        
        for data in can_messages:
            self.send_can_message(0x601, data)
            self.send_can_message(0x602, data)

        self.active = True  # 조이스틱 입력 활성화
        self.get_logger().info("시작됨: 조이스틱 활성화")

    def send_stop_messages(self):
        can_messages = [
            [0x22, 0x40, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00],
        ]
        
        for data in can_messages:
            self.send_can_message(0x601, data)
            self.send_can_message(0x602, data)

        self.active = False  # 조이스틱 입력 비활성화
        self.linear_speed = 0.0
        self.angular_speed = 0.0
        self.get_logger().info("정지됨: 조이스틱 비활성화")

    def timer_callback(self):
        if self.active:  # 활성 상태일 때만 속도 publish
            msg = Twist()
            msg.linear.x = self.linear_speed
            msg.angular.z = self.angular_speed
            self.publisher.publish(msg)

    def run(self):
        self.get_logger().info("Joystick control initialized.")
        try:
            while self.running and rclpy.ok():
                r, _, _ = select.select([self.device.fd], [], [], 0.1)
                if r:
                    for event in self.device.read():
                        if event.type == evdev.ecodes.EV_ABS and self.active:
                            if event.code == evdev.ecodes.ABS_Y:
                                self.linear_speed = self.speed * (1 - event.value / 128.0) if event.value < 128 else -self.speed * ((event.value - 128) / 128.0)
                            elif event.code == evdev.ecodes.ABS_X:
                                self.angular_speed = self.turn * (1 - event.value / 128.0) if event.value < 128 else -self.turn * ((event.value - 128) / 128.0)

                        elif event.type == evdev.ecodes.EV_KEY:
                            if event.code == evdev.ecodes.BTN_NORTH and event.value == 1:  # START 버튼
                                self.send_start_messages()
                            elif event.code == evdev.ecodes.BTN_SOUTH and event.value == 1:  # STOP 버튼
                                self.send_stop_messages()
                
                rclpy.spin_once(self, timeout_sec=0.1)
        except OSError as e:
            self.get_logger().error(f"Joystick disconnected: {e}")
            self.send_stop_messages()
        finally:
            self.device.close()
            rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = JoystickTeleop()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
