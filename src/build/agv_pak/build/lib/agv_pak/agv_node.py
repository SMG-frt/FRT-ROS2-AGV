import can
import keyboard
import time
import threading
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from can_msgs.msg import Frame

# PCAN 채널 설정
channel = "PCAN_USBBUS1"
bus = can.interface.Bus(channel=channel, bustype="pcan", bitrate=1000000)

# 초기 속도 설정
speed_1 = 0
speed_2 = 0
MAX_SPEED = 3000
MIN_SPEED = -3000

class MotorControlNode(Node):

    def __init__(self):
        super().__init__('motor_control_node')
        self.publisher = self.create_publisher(CanFrame, 'can_messages', 10)
        self.declare_parameter("motor_node_ids", [0x601, 0x602])

        # 키보드 이벤트 핸들러 등록
        keyboard.add_hotkey("i", lambda: threading.Thread(target=self.start_motor, args=(0x601,)).start())
        keyboard.add_hotkey("i", lambda: threading.Thread(target=self.start_motor, args=(0x602,)).start())
        keyboard.add_hotkey("p", lambda: (self.stop_motor(0x601), self.stop_motor(0x602)))
        keyboard.add_hotkey("w", self.front)
        keyboard.add_hotkey("s", self.back)
        keyboard.add_hotkey("d", self.right)
        keyboard.add_hotkey("a", self.left)
        keyboard.add_hotkey("c", self.stop_all)
        keyboard.add_hotkey("esc", self.exit_program)
        self.get_logger().info("Motor control program started. Press ESC to exit.")

    def send_can_message(self, arbitration_id, data):
        """CAN 메시지를 전송하는 함수"""
        msg = can.Message(arbitration_id=arbitration_id, data=data, is_extended_id=False)
        try:
            bus.send(msg)
            # ROS 2로 퍼블리시
            can_msg = CanFrame()
            can_msg.id = arbitration_id
            can_msg.data = data
            self.publisher.publish(can_msg)
            self.get_logger().info(f"Sent: ID={hex(arbitration_id)}, Data={data}")
        except can.CanError:
            self.get_logger().error("Message NOT sent")

    def start_motor(self, node_id):
        """모터 시작 함수"""
        commands = [
            [0x22, 0x40, 0x60, 0x00, 0x06, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x07, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x0F, 0x00, 0x00, 0x00],
            [0x22, 0x81, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00],
        ]
        for cmd in commands:
            self.send_can_message(node_id, cmd)
            time.sleep(0.1)

    def stop_motor(self, node_id):
        """모터 정지 함수"""
        self.send_can_message(node_id, [0x22, 0x40, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00])
        time.sleep(0.1)

    def set_motor_front(self, node_id, speed):
        speed = max(MIN_SPEED, min(MAX_SPEED, speed))
        self.send_can_message(node_id, [0x22, 0xFF, 0x60, 0x00, speed & 0xFF, (speed >> 8) & 0xFF, 0x00, 0x00])
        self.get_logger().info(f"Motor {hex(node_id)} speed set to {speed}")

    def set_motor_back(self, node_id, speed):
        speed = max(MIN_SPEED, min(MAX_SPEED, speed))
        self.send_can_message(node_id, [0x22, 0xFF, 0x60, 0x00, speed & 0xFF, (speed >> 8) & 0xFF, 0xFF, 0xFF])
        self.get_logger().info(f"Motor {hex(node_id)} speed set to {speed}")

    def front(self):
        global speed_1, speed_2
        speed_1 = max(speed_1 - 100, MIN_SPEED)
        speed_2 = max(speed_2 - 100, MIN_SPEED)

        if speed_1 < 0:
            self.set_motor_front(0x601, speed_1)
        else:
            self.set_motor_back(0x601, speed_1)

        if speed_2 < 0:
            self.set_motor_front(0x602, speed_2)
        else:
            self.set_motor_back(0x602, speed_2)

        self.get_logger().info(f"Speed decreased: Motor 1 = {speed_1}, Motor 2 = {speed_2}")

    def back(self):
        global speed_1, speed_2
        speed_1 = min(speed_1 + 100, MAX_SPEED)
        speed_2 = min(speed_2 + 100, MAX_SPEED)

        if speed_1 < 0:
            self.set_motor_front(0x601, speed_1)
        else:
            self.set_motor_back(0x601, speed_1)

        if speed_2 < 0:
            self.set_motor_front(0x602, speed_2)
        else:
            self.set_motor_back(0x602, speed_2)

        self.get_logger().info(f"Speed increased: Motor 1 = {speed_1}, Motor 2 = {speed_2}")

    def right(self):
        global speed_1, speed_2
        speed_1 = min(speed_1 + 300, MAX_SPEED)
        speed_2 = min(speed_2 - 300, MAX_SPEED)
        if speed_1 < 0:
            self.set_motor_front(0x601, speed_1)
        else:
            self.set_motor_back(0x601, speed_1)

        if speed_2 < 0:
            self.set_motor_front(0x602, speed_2)
        else:
            self.set_motor_back(0x602, speed_2)
        self.get_logger().info(f"Speed increased: Motor 1 = {speed_1}, Motor 2 = {speed_2}")

    def left(self):
        global speed_1, speed_2
        speed_1 = min(speed_1 - 300, MAX_SPEED)
        speed_2 = min(speed_2 + 300, MAX_SPEED)
        if speed_1 < 0:
            self.set_motor_front(0x601, speed_1)
        else:
            self.set_motor_back(0x601, speed_1)

        if speed_2 < 0:
            self.set_motor_front(0x602, speed_2)
        else:
            self.set_motor_back(0x602, speed_2)
        self.get_logger().info(f"Speed increased: Motor 1 = {speed_1}, Motor 2 = {speed_2}")

    def stop_all(self):
        """속도를 0으로 설정"""
        global speed_1, speed_2
        speed_1, speed_2 = 0, 0
        self.set_motor_front(0x601, 0)
        self.set_motor_front(0x602, 0)
        self.get_logger().info("Motors stopped.")

    def exit_program(self):
        """프로그램 종료"""
        self.stop_all()
        self.stop_motor(0x601)
        self.stop_motor(0x602)
        self.get_logger().info("Exiting program...")
        bus.shutdown()
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    motor_control_node = MotorControlNode()

    # 키보드 이벤트 처리
    keyboard.wait("esc")

if __name__ == "__main__":
    main()

