#!/usr/bin/env python3

# CMakeLists file for the Chapter 4 Example nr. 01: 
# Installable executable
#
# SPDX-License-Identifier: MIT


import os
file_path = os.path.dirname(__file__)

try:
    with open(str(file_path + "/chapter4_greeter_content")) as file:
        print(file.readlines())
except Exception as e:
    print(e)

