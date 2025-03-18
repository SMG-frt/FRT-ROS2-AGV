import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import sys
import canopen

class AgvTestNode(Node):
    def __init__(self):
        super().__init__('agv_test_node')
        self.publisher = self.create_publisher(String, 'can_messages', 10)
        self.get_logger().info("AGV test node has started.")

    def send_message(self, msg):
        self.publisher.publish(String(data=msg))
        self.get_logger().info(f"Sent message: {msg}")

def main(args=None):
    rclpy.init(args=args)
    node = AgvTestNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()

