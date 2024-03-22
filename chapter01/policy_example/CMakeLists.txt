
# CMakeLists file for the Chapter 1 example illustrating how to set a policy
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    ch1_policy_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating a standalone executables"
    LANGUAGES CXX
)

# set policy CMP0121 to the old behavior. CMP0121 is a policy that detects if
# index variables for the list() commands are in a valid format this policy was
# introduced with cmake varsion 3.21
cmake_policy(SET CMP0121 OLD)

# Create a sample list
list(APPEND MYLIST "abc;def;ghi")
# This command will fail if the policy is set to NEW or if the call to
# cmake_policy above is removed as CMake 3.21 sets this policy automatically
list(GET MYLIST "any" OUT_VAR)
