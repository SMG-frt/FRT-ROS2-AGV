from rclpy.node import Node
from can_msgs.msg import Frame
import rclpy

class CanPublisher(Node):
    def __init__(self):
        super().__init__('can_publisher')
        self.publisher = self.create_publisher(Frame, 'can_data', 10)
        timer_period = 0.1  # 10Hz
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = Frame()
        msg.id = 0x123
        msg.dlc = 8
        msg.data = [0, 1, 2, 3, 4, 5, 6, 7]
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    can_publisher = CanPublisher()
    rclpy.spin(can_publisher)
    can_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

