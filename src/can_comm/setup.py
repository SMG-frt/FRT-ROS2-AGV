from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'can_comm'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ub2004',
    maintainer_email='ub2004@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
             'agv_odometry_sub = can_comm.agv_odometry_sub:main',
             'can_velocity = can_comm.can_velocity_node:main',
             'joystick_node = can_comm.joystick_node:main',
             'agv_odometry_pub = can_comm.agv_odometry_pub:main',
             'auto_drive = can_comm.auto_drive:main',
        ],
    },
)
