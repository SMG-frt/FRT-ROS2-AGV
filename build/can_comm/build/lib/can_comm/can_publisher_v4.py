import rclpy
from rclpy.node import Node
from can_msgs.msg import Frame
import sys
import select
import evdev

class CanPublisher(Node):
    def __init__(self):
        super().__init__('can_publisher')
        self.publisher = self.create_publisher(Frame, 'can_data', 10)
        self.timer = self.create_timer(0.1, self.check_joystick_input)
        self.current_speed = 0  # 현재 속도를 0으로 초기화


        self.device_path = "/dev/input/event25"  # NEOCON 장치 경로
        self.device = evdev.InputDevice(self.device_path)

        self.device_fd = self.device.fd

    def check_joystick_input(self):
        r, _, _ = select.select([self.device_fd], [], [], 0.1)
        
        if r:
            for event in self.device.read():
                if event.type == evdev.ecodes.EV_KEY:
                    if event.code == evdev.ecodes.BTN_NORTH:  
                        if event.value == 1:  
                            self.send_start_messages()
                    elif event.code == evdev.ecodes.BTN_SOUTH:  
                        if event.value == 1:  
                            self.send_stop_messages()
                if event.type == evdev.ecodes.EV_ABS:
                    if event.code == evdev.ecodes.ABS_Y:
                        abs_y_value = event.value
                        self.update_speed_based_on_joystick_updown(abs_y_value)
                    if event.code == evdev.ecodes.ABS_Z:
                        abs_z_value = event.value
                        self.update_speed_based_on_joystick_rightleft(abs_z_value)

    def update_speed_based_on_joystick_updown(self, abs_y_value):
        speed = self.map_joystick_value_to_speed_updown(abs_y_value)
        if speed != self.current_speed:
            self.current_speed = speed
            self.get_logger().info(f"Current speed: {self.current_speed}")
            self.send_speed_updown(self.current_speed)

    def update_speed_based_on_joystick_rightleft(self, abs_z_value):
        speed = self.map_joystick_value_to_speed_updown(abs_z_value)
        if speed != self.current_speed:
            self.current_speed = speed
            self.get_logger().info(f"Current speed: {self.current_speed}")
            self.send_speed_rightleft(self.current_speed)

    def map_joystick_value_to_speed_updown(self, abs_y_value):
        min_value = 0
        max_value = 255
        min_speed = -3000
        max_speed = 3000
    
        if abs_y_value <= 128:
            speed = (1 - (abs_y_value / 128)) * max_speed
        else:
            speed = ((abs_y_value - 128) / 127) * min_speed
        
        return int(speed)

    def map_joystick_value_to_speed_rightleft(self, abs_z_value):
        min_value = 0
        max_value = 255
        min_speed = -3000
        max_speed = 3000
    
        if abs_z_value <= 128:
            speed = (1 - (abs_z_value / 128)) * max_speed
        else:
            speed = ((abs_z_value - 128) / 127) * min_speed
        
        return int(speed)


    def send_speed_updown(self, speed):
        if speed < 0:
            data = [
                0x22, 0xFF, 0x60, 0x00,
                (speed & 0xFF),        
                ((speed >> 8) & 0xFF), 
                0xFF, 0xFF
            ]
        else:
            data = [
                0x22, 0xFF, 0x60, 0x00,
                (speed & 0xFF),         
                ((speed >> 8) & 0xFF),  
                0x00, 0x00              
            ]
        
        self.send_can_message(0x601, data)
        self.send_can_message(0x602, data)

    def send_speed_rightleft(self, speed):
        if speed < 0:
            data = [
                0x22, 0xFF, 0x60, 0x00,
                (speed & 0xFF),
                ((speed >> 8) & 0xFF),
                0xFF, 0xFF
            ]
            self.send_can_message(0x601, data)  
        else:
            data = [
                0x22, 0xFF, 0x60, 0x00,
                (speed & 0xFF),
                ((speed >> 8) & 0xFF),
                0x00, 0x00
            ]
            self.send_can_message(0x601, data)  
        
        if speed < 0:
            data = [
                0x22, 0xFF, 0x60, 0x00,
                (speed & 0xFF),
                ((speed >> 8) & 0xFF),
                0xFF, 0xFF
            ]
            self.send_can_message(0x602, data) 
        else:
            data = [
                0x22, 0xFF, 0x60, 0x00,
                (speed & 0xFF),
                ((speed >> 8) & 0xFF),
                0x00, 0x00
            ]
            self.send_can_message(0x602, data)  
    
    def send_start_messages(self):
        can_messages = [
            [0x22, 0x40, 0x60, 0x00, 0x06, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x07, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x0F, 0x00, 0x00, 0x00]
        ]
        
        for data in can_messages:
            self.send_can_message(0x601, data)
            self.send_can_message(0x602, data)

    def send_stop_messages(self):
        can_messages = [
            [0x22, 0x40, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00],
        ]
        
        for data in can_messages:
            self.send_can_message(0x601, data)
            self.send_can_message(0x602, data)

    def send_can_message(self, node_id, data):
        msg = Frame()
        msg.id = node_id
        msg.dlc = len(data)
        msg.data = data
        self.publisher.publish(msg)
        self.get_logger().info(f'Sent CAN message: ID={hex(node_id)}, Data={data}')

def main(args=None):
    rclpy.init(args=args)
    publisher = CanPublisher()
    rclpy.spin(publisher)
    publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
