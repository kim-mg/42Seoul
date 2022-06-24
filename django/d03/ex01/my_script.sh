#!/bin/sh

pip --version
pip install git+https://github.com/jaraco/path.git --log install.log
python3 my_program.py