# CMakeLists creating a simple executable
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    ch3_hello_world_standalone
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating a standalone executables"
    LANGUAGES CXX
)

# Create a target to build an executable
add_executable(ch3_hello_world_standalone)
# Add source files to 'hello_world' target
target_sources(ch3_hello_world_standalone PRIVATE src/main.cpp)
