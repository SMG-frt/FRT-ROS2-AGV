from setuptools import find_packages, setup

package_name = 'agv_pak'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # scripts 디렉토리를 포함시키기 위해 다음 라인을 추가
        ('share/' + package_name + '/scripts', ['scripts/can_talker.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ub2004',
    maintainer_email='ub2004@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'agv_node = agv_pak.agv_node:main',
            'agv_node_2 = agv_pak.agv_node_2:main',
            'agv_test_node.py = agv_test_node:main',
            'can_talker = agv_pak.scripts.can_talker:main',  # 수정된 경로
        ],
    },
)

