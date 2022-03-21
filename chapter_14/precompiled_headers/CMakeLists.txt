# CMakeLists creating a simple executable
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    ch14_precompiled_headers
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating a standalone executables"
    LANGUAGES CXX
)


add_executable(ch14_precompiled_headers)

target_sources(ch14_precompiled_headers PRIVATE 
                src/main.cpp
                src/fibonacci.cpp
                src/eratosthenes.cpp
                src/pythagoras.cpp
                )

target_precompile_headers(ch14_precompiled_headers PRIVATE 
src/fibonacci.h <cstdint> <vector> src/eratosthenes.h)
