#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from can_msgs.msg import Frame
import sys
import termios
import tty
import threading

WHEEL2WHEELWIDTH = 0.75
WHEELRADIUS = 0.732
RAD_TO_RPM = 9.54929

class CanVelocityController(Node):
    def __init__(self):
        super().__init__('can_velocity_controller')
        self.publisher = self.create_publisher(Frame, 'can_data', 10)
        self.subscription = self.create_subscription(Twist, 'cmd_vel', self.velocity_cb, 10)

    def velocity_cb(self, cmd):
        rpm_r = (cmd.linear.x + (cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM
        rpm_l = (cmd.linear.x - (cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM

        rpm_l = max(min(int(rpm_l), 32767), -32768)
        rpm_r = max(min(int(rpm_r), 32767), -32768)

        self.send_can_message(0x601, rpm_l)
        self.send_can_message(0x602, rpm_r)
        self.get_logger().info(f'Sent Speeds -> Left: {rpm_l} RPM, Right: {rpm_r} RPM')

    def send_can_message(self, node_id, speed):
        data = [
            0x22, 0xFF, 0x60, 0x00,
            (speed & 0xFF),
            ((speed >> 8) & 0xFF),
            0xFF if speed < 0 else 0x00,
            0xFF if speed < 0 else 0x00
        ]

        msg = Frame()
        msg.id = node_id
        msg.dlc = 8
        msg.is_extended = False
        msg.data = bytearray(data)

        self.publisher.publish(msg)

class KeyboardTeleop(Node):
    def __init__(self):
        super().__init__('keyboard_teleop')
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.speed = 0.5
        self.turn = 1.0
        self.running = True
        self.thread = threading.Thread(target=self.run)
        self.thread.start()

    def get_key(self):
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            key = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return key

    def run(self):
        self.get_logger().info("Use W/A/S/D to move, X to stop, Q to quit.")
        while self.running and rclpy.ok():
            key = self.get_key()
            msg = Twist()

            if key == 'w':
                msg.linear.x = self.speed
            elif key == 's':
                msg.linear.x = -self.speed
            elif key == 'a':
                msg.angular.z = self.turn
            elif key == 'd':
                msg.angular.z = -self.turn
            elif key == 'x':
                msg.linear.x = 0.0
                msg.angular.z = 0.0
            elif key == 'q':
                self.running = False
                break

            self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    can_node = CanVelocityController()
    teleop_node = KeyboardTeleop()
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(can_node)
    executor.add_node(teleop_node)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        can_node.destroy_node()
        teleop_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
