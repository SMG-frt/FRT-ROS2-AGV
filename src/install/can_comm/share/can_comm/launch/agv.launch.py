from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='can_comm',
            executable='can_velocity', 
            name='can_velocity',
            output='screen'
        ),
        Node(
            package='can_comm',
            executable='joystick_node',
            name='joystick_node',
            output='screen'
        )
    ])
