# CMakeLists creating a simple executable
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    ch14_unity_build
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating a standalone executables"
    LANGUAGES CXX
)


add_executable(ch14_unity_build)
target_compile_features(ch14_unity_build PRIVATE cxx_std_11)

target_sources(ch14_unity_build PRIVATE 
                src/main.cpp
                src/fibonacci.cpp
                src/eratosthenes.cpp
                )

set_source_files_properties(src/eratosthenes.cpp PROPERTIES
                          SKIP_UNITY_BUILD_INCLUSION YES)
