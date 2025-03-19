import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
import math
import sys

class AutonomousDrive(Node):
    def __init__(self, x_target, y_target):
        super().__init__('autonomous_drive')
        self.publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.publisher_turtle = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)

        # 오도메트리 구독 (현재 위치 업데이트)
        self.subscription = self.create_subscription(Odometry, '/odom', self.odometry_callback, 10)
        self.subscription_turtle = self.create_subscription(Odometry, '/turtle1/odom', self.odometry_callback_turtle, 10)


        # 목표 위치 설정 (입력값으로 받음)
        self.x_target = x_target
        self.y_target = y_target
        self.k_linear = 0.5  # 선속도 비율
        self.k_angular = 1.0  # 각속도 비율

        # 초기 로봇 상태
        self.x = 0.0  # x 위치
        self.y = 0.0  # y 위치
        self.theta = 0.0  # 방향 (회전각)

        # 이동 함수 실행
        self.create_timer(0.1, self.navigate_to_target)

    def odometry_callback_turtle(self, msg):
        """터틀심 오도메트리 수신 후 위치 업데이트"""
        self.x_turtle = msg.pose.pose.position.x
        self.y_turtle = msg.pose.pose.position.y
        orientation = msg.pose.pose.orientation
        self.theta_turtle = math.atan2(2 * (orientation.w * orientation.z + orientation.x * orientation.y),
                                       1 - 2 * (orientation.y ** 2 + orientation.z ** 2))


    def odometry_callback(self, msg):
        """오도메트리 수신 후 위치 업데이트"""
        self.x = msg.pose.pose.position.x
        self.y = msg.pose.pose.position.y
        orientation = msg.pose.pose.orientation
        self.theta = math.atan2(2 * (orientation.w * orientation.z + orientation.x * orientation.y),
                                1 - 2 * (orientation.y ** 2 + orientation.z ** 2))

    def navigate_to_target(self):
        # 목표까지 거리 계산
        dx = self.x_target - self.x
        dy = self.y_target - self.y
        distance = math.sqrt(dx ** 2 + dy ** 2)

        # 목표 방향 계산
        target_angle = math.atan2(dy, dx)
        angle_error = target_angle - self.theta

        # 각속도 조정 (각속도 너무 크면 0.5로 제한)
        if angle_error > math.pi:
            angle_error -= 2 * math.pi
        elif angle_error < -math.pi:
            angle_error += 2 * math.pi
        angular_speed = max(min(self.k_angular * angle_error, 2.5), -2.5)  # 회전 속도 제한
        if abs(angular_speed) < 0.1 and abs(angle_error) > 0.05:
            angular_speed = 0.1 * (5 if angular_speed > 0 else -5)

        # 선속도 계산 (최대 0.5 제한)
        linear_speed = min(self.k_linear * distance, 0.5)

        # 목표 도착 여부 확인 (소수점 5자리 반올림)
        if round(self.x, 1) == round(self.x_target, 1) and round(self.y, 1) == round(self.y_target, 1):
            self.get_logger().info(f"목표 도착! 현재 위치 -> X: {self.x:.1f}, Y: {self.y:.1f}")
            return self.stop_movement()

        # Twist 메시지 발행
        twist_msg = Twist()
        twist_msg.linear.x = linear_speed
        twist_msg.angular.z = angular_speed
        self.publisher.publish(twist_msg)

        twist_msg_turtle = Twist()
        twist_msg_turtle.linear.x = linear_speed
        twist_msg_turtle.angular.z = angular_speed
        self.publisher_turtle.publish(twist_msg_turtle)

        self.get_logger().info(f" 이동 중 -> X: {self.x:.3f}, Y: {self.y:.3f}, linear: {linear_speed:.3f}, angular: {angular_speed:.3f}")

    def stop_movement(self):
        """로봇을 멈추는 함수"""
        stop_msg = Twist()
        stop_msg.linear.x = 0.0
        stop_msg.angular.z = 0.0
        self.publisher.publish(stop_msg)

def main(args=None):
    # 명령줄 인자 처리
    if len(sys.argv) != 3:
        print("사용법: python3 <파일명> <목표_x> <목표_y>")
        sys.exit(1)

    x_target = float(sys.argv[1])  # 목표 x 좌표
    y_target = float(sys.argv[2])  # 목표 y 좌표

    rclpy.init(args=args)
    auto_drive = AutonomousDrive(x_target, y_target)
    rclpy.spin(auto_drive)
    auto_drive.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
