from setuptools import find_packages
from setuptools import setup

setup(
    name='canopen_interfaces',
    version='0.2.11',
    packages=find_packages(
        include=('canopen_interfaces', 'canopen_interfaces.*')),
)
