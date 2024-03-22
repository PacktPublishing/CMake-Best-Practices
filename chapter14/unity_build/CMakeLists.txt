# Chapter 14 example to illustrate unity builds in batch mode
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    ch14_unity_build
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate unity-builds"
    LANGUAGES CXX
)

# Create an executable target
add_executable(ch14_unity_build)
target_compile_features(ch14_unity_build PRIVATE cxx_std_11)

target_sources(ch14_unity_build PRIVATE 
                src/main.cpp
                src/fibonacci.cpp
                src/eratosthenes.cpp
                )
# Enable unity build for the target, by default BATCH mode is used                
set_target_properties(ch14_unity_build PROPERTIES UNITY_BUILD True)

# exclude eratosthenes.cpp from the unity build
set_source_files_properties(src/eratosthenes.cpp PROPERTIES
                          SKIP_UNITY_BUILD_INCLUSION YES)
