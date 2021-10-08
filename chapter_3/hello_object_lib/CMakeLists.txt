# Chapter3-  creating a binary library
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.17)

project(
    hello_object
    VERSION 1.0.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating executables and libraries in CMake"
    LANGUAGES CXX
)

# add the library target
add_library(hello_object OBJECT)

# add sources to the library target
target_sources(hello_object PRIVATE src/hello_object.cpp)

# define the C++ standard needed to compile this library and make it visible to
# dependers
target_compile_features(hello_object PUBLIC cxx_std_17)

# set the include directories
target_include_directories(
    hello_object
    PRIVATE src/hello
    PUBLIC include
)
