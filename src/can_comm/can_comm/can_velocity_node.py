#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from can_msgs.msg import Frame

# 상수 정의
WHEEL2WHEELWIDTH = 0.75  
WHEELRADIUS = 0.00732  
RAD_TO_RPM = 9.54929  

class CanVelocityController(Node):
    def __init__(self):
        super().__init__('can_velocity_controller')
        self.publisher = self.create_publisher(Frame, 'can_data', 10)
        self.subscription = self.create_subscription(Twist, '/turtle1/cmd_vel', self.velocity_cb, 10)

    def velocity_cb(self, cmd):
        rpm_r = (cmd.linear.x + (cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM
        rpm_l = (cmd.linear.x - (cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM
        rpm_l, rpm_r = int(max(min(rpm_l, 32767), -32768)), int(max(min(rpm_r, 32767), -32768))

        self.send_can_message(0x601, rpm_l)
        self.send_can_message(0x602, rpm_r)
        self.get_logger().info(f'Sent Speeds -> Left: {rpm_l} RPM, Right: {rpm_r} RPM')

    def send_can_message(self, node_id, speed):
        data = [0x22, 0xFF, 0x60, 0x00, (speed & 0xFF), ((speed >> 8) & 0xFF), 0x00 if speed < 0 else 0xFF, 0x00 if speed < 0 else 0xFF]
        msg = Frame(id=node_id, dlc=8, is_extended=False, data=bytearray(data))
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = CanVelocityController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
