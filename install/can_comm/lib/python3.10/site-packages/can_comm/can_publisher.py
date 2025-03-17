#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from can_msgs.msg import Frame
import evdev
import threading
import select
import time

# 상수 정의
WHEEL2WHEELWIDTH = 0.75  # 휠 사이 거리
WHEELRADIUS = 0.00732  # 휠 반지름
RAD_TO_RPM = 9.54929  # rad/s -> RPM 변환 상수

class CanVelocityController(Node):
    def __init__(self):
        super().__init__('can_publisher')
        self.publisher = self.create_publisher(Frame, 'can_data', 10)
        self.subscription = self.create_subscription(Twist, '/turtle1/cmd_vel', self.velocity_cb, 10)

    def velocity_cb(self, cmd):
        # Twist 메시지를 RPM으로 변환
        rpm_r = (cmd.linear.x + (cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM
        rpm_l = (cmd.linear.x - (cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM

        # RPM을 CAN 메시지에 맞는 범위로 제한
        rpm_l = max(min(int(rpm_l), 32767), -32768)
        rpm_r = max(min(int(rpm_r), 32767), -32768)

        self.send_can_message(0x601, rpm_l)
        self.send_can_message(0x602, rpm_r)
        self.get_logger().info(f'Sent Speeds -> Left: {rpm_l} RPM, Right: {rpm_r} RPM')

    def send_can_message(self, node_id, speed):
        # CAN 메시지 데이터 준비
        data = [
            0x22, 0xFF, 0x60, 0x00,
            (speed & 0xFF),
            ((speed >> 8) & 0xFF),
            0xFF if speed < 0 else 0x00,
            0xFF if speed < 0 else 0x00
        ]

        # Frame 메시지 준비
        msg = Frame()
        msg.id = node_id
        msg.dlc = 8
        msg.is_extended = False
        msg.data = bytearray(data)

        # CAN 데이터 발행
        self.publisher.publish(msg)

class JoystickTeleop(Node):
    def __init__(self):
        super().__init__('joystick_teleop')
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.can_publisher = self.create_publisher(Frame, 'can_data', 10) 
        
        # 조이스틱 장치 경로 설정
        self.device_path = self.find_joystick_device("NEOCON")
        if self.device_path is None:
            self.get_logger().error("NEOCON 조이스틱을 찾을 수 없습니다.")
            raise RuntimeError("NEOCON 조이스틱이 연결되지 않음")
        self.device = evdev.InputDevice(self.device_path)
        self.device_fd = self.device.fd
        self.running = True
        
        # 속도 및 회전율 설정
        self.speed = 2.0
        self.turn = 1.0

        # 현재 속도 상태 (초기값 0)
        self.linear_speed = 0.0
        self.angular_speed = 0.0

        # 조이스틱 입력을 처리하는 스레드 시작
        self.thread = threading.Thread(target=self.run)
        self.thread.start()

    def find_joystick_device(self, target_name):
        """NEOCON 조이스틱 자동 검색"""
        devices = [evdev.InputDevice(path) for path in evdev.list_devices()]
        for device in devices:
            if target_name in device.name:
                self.get_logger().info(f"조이스틱 찾음: {device.name} ({device.path})")
                return device.path
        return None

    def send_can_message(self, node_id, data):
        msg = Frame()
        msg.id = node_id
        msg.dlc = len(data)
        msg.is_extended = False
        msg.data = bytearray(data)

        self.can_publisher.publish(msg)

    def send_start_messages(self):
        can_messages = [
            [0x22, 0x40, 0x60, 0x00, 0x06, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x07, 0x00, 0x00, 0x00],
            [0x22, 0x40, 0x60, 0x00, 0x0F, 0x00, 0x00, 0x00]
        ]
        
        for data in can_messages:
            self.send_can_start_stop_message(0x601, data)
            self.send_can_start_stop_message(0x602, data)

    def send_stop_messages(self):
        can_messages = [
            [0x22, 0x40, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00],
        ]
        
        for data in can_messages:
            self.send_can_start_stop_message(0x601, data)
            self.send_can_start_stop_message(0x602, data)

    def send_can_start_stop_message(self, node_id, data):
        msg = Frame()
        msg.id = node_id
        msg.dlc = len(data)
        msg.data = data
        self.can_publisher.publish(msg)
        self.get_logger().info(f'Sent CAN message: ID={hex(node_id)}, Data={data}')


    def run(self):
        self.get_logger().info("Joystick control initialized. Move with joystick.")
        
        while self.running and rclpy.ok():
            # select를 사용하여 조이스틱 장치에서 읽을 데이터가 준비되었는지 확인
            r, _, _ = select.select([self.device_fd], [], [], 0.1)
            
            if r:
                for event in self.device.read():
                    if event.type == evdev.ecodes.EV_KEY:
                        if event.code == evdev.ecodes.BTN_NORTH:  # BTN_NORTH: 시작
                            if event.value == 1:
                                self.send_start_messages()
                        elif event.code == evdev.ecodes.BTN_SOUTH:  # BTN_SOUTH: 정지
                            if event.value == 1:
                                self.send_stop_messages()

                    if event.type == evdev.ecodes.EV_ABS:
                        # 상하 방향 (전진/후진)
                        if event.code == evdev.ecodes.ABS_Y:
                            if event.value < 128:  # 후진
                                self.linear_speed = self.speed * (1 - event.value / 128.0)
                            else:  # 전진
                                self.linear_speed = -self.speed * ((event.value - 128) / 128.0)

                        # 좌우 방향 (회전)
                        elif event.code == evdev.ecodes.ABS_X:
                            if event.value < 128:  # 왼쪽
                                self.angular_speed = self.turn * (1 - event.value / 128.0)
                            else:  # 오른쪽
                                self.angular_speed = -self.turn * ((event.value - 128) / 128.0)

                        # 회전 조작 (ABS_Z 사용)
                        elif event.code == evdev.ecodes.ABS_Z:
                            if event.value < 128:  # 왼쪽
                                self.angular_speed = self.turn * (1 - event.value / 128.0)
                            else:  # 오른쪽
                                self.angular_speed = -self.turn * ((event.value - 128) / 128.0)


                # Twist 메시지 생성
                msg = Twist()
                msg.linear.x = self.linear_speed
                msg.angular.z = self.angular_speed

                # 조이스틱 값으로 속도 업데이트
                self.publisher.publish(msg)
                
            rclpy.spin_once(self, timeout_sec=0.1)

    def stop(self):
        self.running = False
        self.device.close()

def main(args=None):
    rclpy.init(args=args)
    can_node = CanVelocityController()
    joystick_node = JoystickTeleop()
    
    # 멀티 스레드로 실행
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(can_node)
    executor.add_node(joystick_node)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        joystick_node.stop()
        can_node.destroy_node()
        joystick_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
