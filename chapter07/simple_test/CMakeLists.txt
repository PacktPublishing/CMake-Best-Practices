
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  "ch7_simple_test"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

# Enable testing for this project
enable_testing()  
# Ad the executalbe to test
add_executable(ch7_simple_test)
target_sources(ch7_simple_test PRIVATE src/main.cpp)

# Add a test called example_test which executes the command `ch7_simple_test`
add_test(NAME example_test COMMAND ch7_simple_test)

# Add a test called example_test_2 which executes the command `ch7_simple_test` with the argument `arg1`
add_test(NAME example_test_2 COMMAND ch7_simple_test arg1)

