# Top-level CMakeLists file for the Chapter 4 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "CMake Tips and Tricks Chapter 4"
  VERSION 1.0
  DESCRIPTION
    "A collection of sample C++ applications and libraries to demonstrate creating libraries and executables"
  LANGUAGES CXX)

set(CMAKE_PREFIX_PATH /tmp/install-dir)
find_package(ch4_ex05_lib CONFIG REQUIRED)

add_executable(hello src/main.cpp)
target_link_libraries(hello ch4_ex05_lib::ch4_ex05_lib)