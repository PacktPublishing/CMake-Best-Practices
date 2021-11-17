
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_sanitizers"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using various sanitizers"
  LANGUAGES CXX)
  
enable_testing()
add_executable(ch7_sanitizers)
target_sources(ch7_sanitizers PRIVATE src/main.cpp)
target_compile_options(ch7_sanitizers PRIVATE -fsanitize=address)
target_link_options(ch7_sanitizers PRIVATE -fsanitize=address)

add_test(NAME sanitizer_test COMMAND ch7_sanitizers)
# The test will fail because of address sanitizer violations
set_tests_properties(sanitizer_test PROPERTIES WILL_FAIL True)
