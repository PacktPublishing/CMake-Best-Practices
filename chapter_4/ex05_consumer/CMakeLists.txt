# CMakeLists file for the Chapter 4 Example nr. 05: 
# Example CMake consumer for Config-file package
#
# SPDX-License-Identifier: MIT


cmake_minimum_required(VERSION 3.21)

project(
  ch4_ex05_consumer
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 05, Out ot project config-file package consumer"
  LANGUAGES CXX)

set(CMAKE_PREFIX_PATH /tmp/install-dir)

# Let's find our package. We're explicitly specifying CONFIG argument
# to not to search for MODULE packages. CMake will fail if package is not present
# since REQUIRED argument is given
find_package(ch4_ex05_lib CONFIG REQUIRED)

# Define an executable
add_executable(ch4_ex05_consumer src/main.cpp)
# Link executable to ch4_ex05_lib package we've found before. Target is under 
# `ch4_ex05_lib::` namespace since export is made using that namespace. 
target_link_libraries(ch4_ex05_consumer ch4_ex05_lib::ch4_ex05_lib)