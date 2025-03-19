#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from can_msgs.msg import Frame

# 상수 정의
WHEEL2WHEELWIDTH = 0.75  
WHEELRADIUS = 0.0153
RAD_TO_RPM = 9.54929  

class CanVelocityController(Node):
    def __init__(self):
        super().__init__('can_velocity_controller')
        self.publisher = self.create_publisher(Frame, 'can_data', 10)
        self.subscription = self.create_subscription(Twist, '/cmd_vel', self.velocity_cb, 10)

        # 노드가 시작될 때 초기 CAN 메시지를 보내기
        self.send_start_messages()
    
    def send_can_start_message(self, node_id, data):
        msg = Frame(id=node_id, dlc=len(data), is_extended=False, data=bytearray(data))
        self.publisher.publish(msg)  

    def send_start_messages(self):
        can_messages = [
            [0x2b, 0x40, 0x60, 0x00, 0x80, 0x00, 0x00, 0x00],
            [0x2b, 0x40, 0x60, 0x00, 0x80, 0x00, 0x00, 0x00],
            [0x2f, 0x60, 0x60, 0x00, 0x03, 0x00, 0x00, 0x00],
            [0x2f, 0x60, 0x60, 0x00, 0x03, 0x00, 0x00, 0x00]
        ]
        for data in can_messages:
            self.send_can_start_message(0x601, data)
            self.send_can_start_message(0x602, data)

    def velocity_cb(self, cmd):
        rpm_r = (-cmd.linear.x + (-cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM
        rpm_l = (-cmd.linear.x - (-cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM
        rpm_l, rpm_r = int(max(min(rpm_l, 32767), -32768)), int(max(min(rpm_r, 32767), -32768))

        self.send_can_message(0x601, rpm_l)
        self.send_can_message(0x602, rpm_r)
        self.get_logger().info(f'Sent Speeds -> Left: {rpm_l} RPM, Right: {rpm_r} RPM')

    def send_can_message(self, node_id, speed):
        # CAN 메시지 데이터 준비
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
    
        # Frame 메시지 준비
        msg = Frame()
        msg.id = node_id
        msg.dlc = 8
        msg.is_extended = False
        msg.data = bytearray(data)

        # CAN 데이터 발행
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = CanVelocityController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
