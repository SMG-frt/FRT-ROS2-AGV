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
            if key == 'p':
                self.send_stop_messages()
    
    def send_start_messages(self):
        can_messages = [
            [0x22, 0x40, 0x60, 0x00, 0x06, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x07, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x0F, 0x00, 0x00, 0x00]
        ]
        
        for data in can_messages:
            msg = Frame()
            msg.id = 0x601
            msg.dlc = len(data)
            msg.data = data
            self.publisher.publish(msg)
            self.get_logger().info(f'Publishing: {msg.data}')
    
    def send_stop_messages(self):
        can_messages = [
            [0x22, 0x40, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00],
        ]
        
        for data in can_messages:
            msg = Frame()
            msg.id = 0x601
            msg.dlc = len(data)
            msg.data = data
            self.publisher.publish(msg)
            self.get_logger().info(f'Publishing: {msg.data}')
     

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

