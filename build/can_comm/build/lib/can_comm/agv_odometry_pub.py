import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Point, Quaternion
import math
from can_msgs.msg import Frame

class OdometryPublisher(Node):
    def __init__(self):
        super().__init__('odometry_publisher')
        self.publisher_ = self.create_publisher(Odometry, '/odom', 10)
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.subscription = self.create_subscription(
            Twist, '/cmd_vel', self.velocity_callback, 10
        )
        self.x = 0.0  # 로봇의 x 위치
        self.y = 0.0  # 로봇의 y 위치
        self.theta = 0.0  # 로봇의 방향 (회전각)

    def velocity_callback(self, msg):
        # 선속도와 각속도를 읽음
        v_linear = msg.linear.x  # 선속도
        v_angular = msg.angular.z  # 각속도

        # 시간 간격 (DT)
        dt = 0.1  # 예시로 0.1초

        # 위치 업데이트 (간단한 오도메트리 계산)
        self.x += v_linear * dt * math.cos(self.theta)
        self.y += v_linear * dt * math.sin(self.theta)
        self.theta += v_angular * dt

        # 오도메트리 메시지 발행
        odom_msg = Odometry()
        odom_msg.header.stamp = self.get_clock().now().to_msg()
        odom_msg.header.frame_id = 'odom'

        # 위치와 방향을 메시지에 설정
        odom_msg.pose.pose.position = Point()  # Point 객체를 먼저 생성
        odom_msg.pose.pose.position.x = self.x  # x 값 설정
        odom_msg.pose.pose.position.y = self.y  # y 값 설정
        odom_msg.pose.pose.position.z = 0.0    # z 값 설정

        # 쿼터니언 값 설정 (w, x, y, z)
        odom_msg.pose.pose.orientation = Quaternion(x=0.0, y=0.0, z=math.sin(self.theta / 2), w=math.cos(self.theta / 2))

        self.publisher_.publish(odom_msg)

    def send_can_message(self, node_id, data):
        msg = Frame(id=node_id, dlc=len(data), is_extended=False, data=bytearray(data))
        self.can_publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    odom_publisher = OdometryPublisher()

    rclpy.spin(odom_publisher)  # ROS 2 노드를 실행시킴

    # 종료 시 노드 정리
    odom_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
