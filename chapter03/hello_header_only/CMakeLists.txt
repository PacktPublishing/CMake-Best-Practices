# Chapter 3 - Example illustrating how to create a header only library
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    ch3_hello_header_only
    VERSION 1.0
    DESCRIPTION "Chapter 3 header only example"
    LANGUAGES CXX
)

# Create a library target
add_library(ch3_hello_header_only INTERFACE)

# expose the include directories
target_include_directories(ch3_hello_header_only INTERFACE include/)
# expose the minium C++ standard needed to compile this library
target_compile_features(ch3_hello_header_only INTERFACE cxx_std_17)
