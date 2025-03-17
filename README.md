# FRT-ROS2-AGV
 ## humble 설치방법
- sudo apt install software-properties-common

- sudo add-apt-repository universe

- sudo apt update && sudo apt install curl -y

- sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/key

- echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

- sudo update

- sudo upgrade 

- sudo apt install ros-humble-desktop

- sudo apt install ros-humble-desktop

- source /opt/ros/humble/setup.bash

### 다깔린지 확인 TEST
1. 터미널 2개를 킨다
2. 1번 터미널 : ros2 run demo_nodes_cpp talker
3. 2번 터미널 : ros2 run demo_nodes_cpp listener
4. 설치가 잘된거라면 listener 터미널에서 I heard 숫자가 나옴
-------------------------------------------------------------------------------------------------------------------------------------------------------
## canopen 설치방법
1. 작업환경을 만든다 
- mkdir -p ~/ros2_ws/src
2. src 폴더로 들어온다.
- cd ~/ros2_ws/src
3. src 폴더에 git clone -b humble 로 깃허브에 있는 코드를 humble버전으로 다운받는다.
- git clone -b humble https://github.com/ros-industrial/ros2_canopen.git
4. ros2_ws 폴더로 돌아와 빌드를 진행 한다.
- cd ~/ros2_ws
- colcon build
4. (선택) 만약 이미 깔려있는 페키지가 있다면 선택하여 빌드를 진행한다. 
- colcon build --packages-select ros2_canopen
5. 빌드가 완료되면 가지고 있는 CAN Controller Setup을 진행한다.
    1.  Peak CANController
   - sudo modprobe peak_usb				<== 디바이스 설정
   - sudo ip link set can0 up type can bitrate 1000000 <== 비트레이트 1M
   - sudo ip link set can0 txqueuelen 1000		<== 송신 전송 큐 길이 1000 
   - sudo ip link set up can0			<== can0 으로 이름지저정

   2. candleLight USB-CAN Adapter
    - sudo modprobe gs_usb
    - sudo ip link set can0 up type can bitrate 1000000
    - sudo ip link set can0 txqueuelen 1000
    - sudo ip link set up can0
6. can 값 확인법
- sudo apt install can-utils  <=== can명령어를 보내기위한 apt
- 1번 터미널 : candump can0
- 2번 터미널 : cansend can0 123#11223344
- 1번에 들어온 값이 2번에서 보낸 값이랑 같다면 성공!
7. can setup 자동설정하기
    1. 자동 실행을 위한 서비스 생성
    - sudo nano /etc/systemd/system/can_setup.service 
    2. 서비스 파일에 적어야하는것들
    ```css
    [Unit]
    Description=Set up CAN interface at boot /*<= 이름*/
    After=network.target


    [Service]
    Type=oneshot
    ExecStart=/bin/bash -c "modprobe peak_usb && ip link set can0 up type can bitrate 1000000 && ip link set>	/*<== 실행 되어야 되는 것들*/
    RemainAfterExit=true

    [Install]
    WantedBy=multi-user.target
    ```
    3. 파일 저장후 서비스 활성화 
    - sudo systemctl daemon-reload  <== 새로운 서비스 인식
    - sudo systemctl enable can-interface.service  <== 부팅시 시작하도록 설정
    - sudo systemctl start can-interface.service   <== 즉시 시작
   1. 리붓 
    - sudo reboot <== 재부팅을 하면 그다음부터 백그라운드로 실행됨
-------------------------------------------------------------------------------------------------------------------------------------------------------
## ros2 패키지 생성
1. 본인의 워크스페이스에 들어간다.
- cd ~/ros2_ws/src
2. 패키지 생성하기
- python 패키지
  - ros2 pkg create 패키지이름 --build-type ament_python

- c,c++ 패키지
    - ros2 pkg create 패키지이름 --build-type ament_cmake

### ex) 패키지 tree
```
test_py
├── package.xml
├── resource
│   └── test_py
├── setup.cfg
├── setup.py
├── test
│   ├── test_copyright.py
│   ├── test_flake8.py
│   └── test_pep257.py
└── test_py
    └── __init__.py

```
3. 패키지 생성후 빌드 하기
- colcon build --packages-select 패키지이름
- ex)colcon build --packages-select test_py
4. 빌드후 환경설정
- source install/setup.bash
5. 파일 생성하기
    1. 생성하는 파일 위치는 ~/ros2_ws/src/test_py/test_py 에 생성한다.

### ex)
``` python
# test_py/tt.py
def main():
    print("hi py")
```
2. 파일 생성후
- ros2_ws/src/test_py/setup.py 파일 수정
```python
entry_points={
        'console_scripts': [
            'tt = test_py.tt:main', 
            #<=== tt = 실행 시킬 이름, test_py.tt::main = test_py 패키지에 있는 
            # tt.py 에서 main을 실행
        ],
    },
```
3. 패키지 빌드 진행
- colcon build --packages-select test_py

4. 워크스페이스 업데이트
- source ~/ros2_ws/install/setup.bash

5. 패키지 실행하기
### ex)
- ros2 run test_py tt <== test_py = 패키지  이름, tt = 실행 시킬 이름
-------------------------------------------------------------------------------------------------------------------------------------------------------
## PC1 설정법
1. bashrc 파일을 수정 한다
- sudo nano ~/.bashrc  PW: 1 <=== 로그인 비밀번호
2. bashrc 파일 가장 밑에 밑의 명령어를 적는다.
```python
  source /opt/ros/humble/setup.bash  #<== ros2 humble 실행
  source ~/ros2_ws/install/setup.bash #<== ros2_ws 라는 작업디랙토리 설정
  export ROS_DOMAIN_ID=0  #<== 도메인 설정 0(기본) 같은 도메인끼리 연결
  export ROS_IP=192.168.0.7 #<== 개인 IP
  export RMW_IMPLEMENTATION=rmw_fastrtps_cpp #<== fastDDS 설정
  #nano로 연 경우 저장방법은 Ctrl+x -> y 순서임
```
-------------------------------------------------------------------------------------------------------------------------------------------------------
## 로봇1(라즈베리파이) 설정법
1. bashrc 파일을 수정 한다
- 명령어 : sudo nano ~/.bashrc  PW: 1 <=== 로그인 비밀번호
2. bashrc 파일 가장 밑에 밑의 명령어를 적는다.
```python
  source /opt/ros/humble/setup.bash  #<== ros2 humble 실행
  source ~/ros2_ws/install/setup.bash #<== ros2_ws 라는 작업디랙토리 설정
  export ROS_DOMAIN_ID=0  #<== 도메인 설정 0(기본) 같은 도메인끼리 연결
  export ROS_IP=192.168.0.7 #<== 개인 IP
  export RMW_IMPLEMENTATION=rmw_fastrtps_cpp #<== fastDDS 설정
  #nano로 연 경우 저장방법은 Ctrl+x -> y 순서임
```
-------------------------------------------------------------------------------------------------------------------------------------------------------
## 원격 연결
1. pc1과 로봇1 같은 WIFI 연결한다
- ID: mobie_AGV_WIFI_5G
- PW: ubuntu2204
-------------------------------------------------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------------------------------------------------
## 로봇1에서 리스닝하기 위한 코드 can_listener.py 설명 
```python
import rclpy #노드 작성을 위한 라이브러리
from rclpy.node import Node #Node 클래스를 사용하여 노드정이
from can_msgs.msg import Frame #can 송수신을 위한 라이브러리
import subprocess  #외부명령어를 실행및 출력

class CanListener(Node):
    def __init__(self):
        super().__init__('can_listener')
        # 'can_data' 토픽 구독
        self.subscription = self.create_subscription(
            Frame,
            'can_data',  # 구독할 토픽 이름
            self.listener_callback,
            10  # 큐 크기
        )

    def listener_callback(self, msg):
        # 받은 CAN 메시지를 candump 형식으로 처리
        can_id = hex(msg.id)  # CAN ID를 16진수로 변환
        # 데이터 부분을 8바이트 이하로 자르고 16진수 문자열로 변환
        data = ''.join([f'{byte:02x}' for byte in msg.data])

        self.get_logger().info(f'Received CAN message: ID={can_id}, Data={data}')

        # 수신된 데이터를 기반으로 변경된 데이터를 전송
        modified_data = self.modify_data(data)

        # 수신된 메시지를 cansend로 전송
        self.send_can_message('can0', can_id, modified_data)

    def modify_data(self, data):
        # 수신된 데이터를 변경하는 로직
        # 예를 들어 마지막 바이트를 0x06에서 0x0f로 변경
        if data.endswith('60000000'):
            data = data[:-2] + '0f000000'
        return data

    def send_can_message(self, interface, can_id, data):
        # cansend 명령어를 사용하여 CAN 메시지를 전송
        can_id = can_id.lstrip('0x')  # 16진수 ID에서 '0x'를 제거
        command = f"cansend {interface} {can_id}#{data}"
        try:
            subprocess.run(command, shell=True, check=True)
            self.get_logger().info(f'Sent CAN message: {command}')
        except subprocess.CalledProcessError as e:
            self.get_logger().error(f'Failed to send CAN message: {e}')

def main(args=None):
    rclpy.init(args=args)
    listener = CanListener()
    rclpy.spin(listener) 
    listener.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
```
-------------------------------------------------------------------------------------------------------------------------------------------------------
## pc1에서 퍼브리싱 위한 코드 can_pblisher.py 설명 
```python
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
WHEELRADIUS = 0.732  # 휠 반지름
RAD_TO_RPM = 9.54929  # rad/s -> RPM 변환 상수

class CanVelocityController(Node):
    def __init__(self):
        super().__init__('can_velocity_controller')
        self.publisher = self.create_publisher(Frame, 'can_data', 10)
        self.subscription = self.create_subscription(Twist, '/turtle1/cmd_vel', self.velocity_cb, 10)  #터틀심 태스트를 위한 구독

    def velocity_cb(self, cmd):
        # Twist 메시지를 RPM으로 변환
        rpm_r = (cmd.linear.x + (cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM
        rpm_l = (cmd.linear.x - (cmd.angular.z * WHEEL2WHEELWIDTH / 2)) / WHEELRADIUS * RAD_TO_RPM

        # RPM을 CAN 메시지에 맞는 범위로 제한
        rpm_l = max(min(int(rpm_l), 32767), -32768)
        rpm_r = max(min(int(rpm_r), 32767), -32768)

        self.send_can_message(0x601, rpm_l) #왼쪽
        self.send_can_message(0x602, rpm_r) #오른쪽
        self.get_logger().info(f'Sent Speeds -> Left: {rpm_l} RPM, Right: {rpm_r} RPM') 

    def send_can_message(self, node_id, speed):
        # CAN 메시지 데이터 준비
        # can 값은 전진일경우 0x00 으로 끝나며 후진일경우 0xff 로 끝남
        data = [
            0x22, 0xFF, 0x60, 0x00,
            (speed & 0xFF),
            ((speed >> 8) & 0xFF),
            0xFF if speed < 0 else 0x00,
            0xFF if speed < 0 else 0x00
        ]

        # can Frame 메시지 준비
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
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10) #터틀심 테스트 용 구독
        
        # 조이스틱 장치 경로 설정
        self.device_path = "/dev/input/event27"  #조이스틱 등록 이벤트 명령어
        self.device = evdev.InputDevice(self.device_path)
        self.device_fd = self.device.fd
        self.running = True
        
        # 속도 및 회전율 설정
        self.speed = 1.0  #선속도
        self.turn = 1.0   #각속도

        # 현재 속도 상태 (초기값 0)
        self.linear_speed = 0.0
        self.angular_speed = 0.0

        # 조이스틱 입력을 처리하는 스레드 시작
        self.thread = threading.Thread(target=self.run)
        self.thread.start()

    def run(self):
        self.get_logger().info("Joystick control initialized. Move with joystick.")
        
        while self.running and rclpy.ok():
            # select를 사용하여 조이스틱 장치에서 읽을 데이터가 준비되었는지 확인
            r, _, _ = select.select([self.device_fd], [], [], 0.1)
            
            if r:
                for event in self.device.read():
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

                    if event.type == evdev.ecodes.EV_KEY:
                        # BTN_START (315번 버튼) 상태 변경 감지
                        if event.code == 315:
                            if event.value == 1:  # 버튼이 눌렸을 때
                                # 토글 기능: 1초마다 버튼 상태 변경
                                if time.time() - self.last_toggle_time > self.toggle_interval:
                                    self.button_state = not self.button_state
                                    self.last_toggle_time = time.time()
                                    self.get_logger().info(f"Button state toggled: {self.button_state}")

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
    
    #조이스틱과 can명령어 보내는 2가지 작업 멀티 스레드로 실행
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
```