from setuptools import find_packages
from setuptools import setup

setup(
    name='cogen',
    version='0.2.11',
    packages=find_packages(
        include=('cogen', 'cogen.*')),
)
