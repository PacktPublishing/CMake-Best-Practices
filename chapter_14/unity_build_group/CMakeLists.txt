# CMakeLists creating a simple executable
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    ch14_unity_build_group
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating a standalone executables"
    LANGUAGES CXX
)


add_executable(ch14_unity_build_group)

target_sources(ch14_unity_build_group PRIVATE 
                src/main.cpp
                src/fibonacci.cpp
                src/eratosthenes.cpp
                src/pythagoras.cpp
                )

set_target_properties(ch14_unity_build_group PROPERTIES UNITY_BUILD_MODE GROUP)

set_source_files_properties(src/main.cpp src/fibonacci.cpp PROPERTIES UNITY_GROUP group1)

set_source_files_properties(src/erathostenes.cpp src/pythagoras.cpp PROPERTIES UNITY_GROUP group2)