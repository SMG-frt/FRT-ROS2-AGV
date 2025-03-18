import rclpy
from rclpy.node import Node
from can_msgs.msg import Frame
import sys
import select

class CanPublisher(Node):
    def __init__(self):
        super().__init__('can_publisher')
        self.publisher = self.create_publisher(Frame, 'can_data', 10)
        self.timer = self.create_timer(0.1, self.check_keyboard_input)

    def check_keyboard_input(self):
        if sys.stdin in select.select([sys.stdin], [], [], 0)[0]:
            key = sys.stdin.read(1)
            if key == 'i':
                self.send_start_messages()
            elif key == 'p':
                self.send_stop_messages()
            elif key == '1':
                self.send_gear_speed(0x601, 1) 
                self.send_gear_speed(0x602, 1)   
            elif key == '2':
                self.send_gear_speed(0x601, 2) 
                self.send_gear_speed(0x602, 2) 
            elif key == '3':
                self.send_gear_speed(0x601, 3)
                self.send_gear_speed(0x602, 3) 
            elif key == '4':
                self.send_gear_speed(0x601, 4)
                self.send_gear_speed(0x602, 4) 

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
    
    def send_gear_speed(self, node_id, gear):
        gear_speeds = {
            1: 100,    # 1단은 100
            2: 300,    # 2단은 300
            3: 500,    # 3단은 500
            4: 700,    # 4단은 700 
        }
        
        if gear in gear_speeds:
            speed = gear_speeds[gear]
        else:
            self.get_logger().error(f"Invalid gear: {gear}")
            return
        
        data = [
            0x22, 0xFF, 0x60, 0x00,
            speed & 0xFF,        
            (speed >> 8) & 0xFF,  
            0x00, 0x00
        ]
        
        self.send_can_message(node_id, data)

    def send_can_message(self, node_id, data):
        """CAN 메시지를 전송하는 공통 함수"""
        msg = Frame()
        msg.id = node_id
        msg.dlc = len(data)
        msg.data = data
        self.publisher.publish(msg)
        self.get_logger().info(f'Sent CAN message: ID={hex(node_id)}, Data={data}')

def main(args=None):
    import tty, termios
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    tty.setcbreak(fd)
    
    try:
        rclpy.init(args=args)
        publisher = CanPublisher()
        rclpy.spin(publisher)
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        publisher.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

