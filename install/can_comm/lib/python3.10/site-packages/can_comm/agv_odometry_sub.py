import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry

class OdometryListener(Node):
    def __init__(self):
        super().__init__('odometry_listener')
        # /odom 토픽을 구독하여 오도메트리 메시지를 받음
        self.subscription = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10
        )

    def odom_callback(self, msg):
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        theta = msg.pose.pose.orientation.z 

        self.get_logger().info(f'Position -> X: {x}, Y: {y}, Theta: {theta}')

def main(args=None):
    rclpy.init(args=args)
    odom_listener = OdometryListener()

    # ROS 2 노드 실행
    rclpy.spin(odom_listener)

    # 종료 시 노드 정리
    odom_listener.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
