# ______________________________________________________ Top-level CMakeLists
# file for the Chapter 2 example content.
#
# @file     CMakeLists.txt @author   Dominik Berner <dominik.berner@gmail.com>
# @date     19.09.2021
#
# SPDX-License-Identifier: MIT
# ______________________________________________________
cmake_minimum_required(VERSION 3.21)

project(
  "CMake Tips and Tricks Chapter 3"
  VERSION 1.0
  DESCRIPTION
    "A collection of sample C++ applications and libraries to demonstrate creating libraries and executables"
  LANGUAGES CXX)

add_subdirectory(hello_world_standalone)
add_subdirectory(hello_lib)
add_subdirectory(hello_header_only)
