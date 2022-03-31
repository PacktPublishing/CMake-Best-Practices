
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_test_labels"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

enable_testing()  
add_executable(ch7_test_labels)
target_sources(ch7_test_labels PRIVATE src/main.cpp)

add_test(NAME labeled_test COMMAND ch7_test_labels)
set_tests_properties(labeled_test PROPERTIES LABELS "example")

add_test(NAME labeled_test_2 COMMAND ch7_test_labels extra_arg)
set_tests_properties(labeled_test_2 PROPERTIES LABELS "will_fail" WILL_FAIL True)




