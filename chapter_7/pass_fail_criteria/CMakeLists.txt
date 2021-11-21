
# CMakeLists file for the Chapter 7 example, showing a simple project wthat tests for a specific string
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_pass_fail_criteria"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)
add_executable(ch7_pass_fail_criteria)
target_sources(ch7_pass_fail_criteria PRIVATE src/main.cpp)

add_test(NAME pass_fail_test COMMAND ch7_pass_fail_criteria ARG1)
set_tests_properties(pass_fail_test PROPERTIES 
                                    FAIL_REGULAR_EXPRESSION "[W|w]arning|[E|e]rror"
                                    PASS_REGULAR_EXPRESSION "[S|s]uccess")

