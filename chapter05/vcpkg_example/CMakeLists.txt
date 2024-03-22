# Chapter 5- Example tto illustrate creating a simple executable that links library retrieved with vcpkg
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    ch5_vcpkg_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate retrieving third-party dependencies with vcpkg"
    LANGUAGES CXX
)

find_package(RapidJSON QUIET)
if(NOT RapidJSON_FOUND)
    message(WARNING "RapidJSON not found, skipping vcpkg example")
endif()

# Create a target to build an executable
add_executable(ch5_vcpkg_example)
# set the c++ version required

target_compile_features(
    ch5_vcpkg_example
    PRIVATE cxx_std_11
)
# Add source files to 'hello_world' target
target_sources(
    ch5_vcpkg_example
    PRIVATE src/main.cpp
)

# link the fmt library to the executable
target_link_libraries(
    ch5_vcpkg_example
    PRIVATE rapidjson
)
