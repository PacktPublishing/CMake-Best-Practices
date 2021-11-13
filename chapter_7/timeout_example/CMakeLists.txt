
# CMakeLists file for the Chapter 7 example, showing a simple project wthat tests for a specific string
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_test_timeout_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)
enable_testing()
add_executable(ch7_test_timeout_example)
target_sources(ch7_test_timeout_example PRIVATE src/main.cpp)
target_compile_features(ch7_test_timeout_example PRIVATE cxx_std_17)

add_test(NAME timeout_test COMMAND ch7_test_timeout_example)
set_tests_properties(timeout_test PROPERTIES TIMEOUT 10)

