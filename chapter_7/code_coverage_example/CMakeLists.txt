
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_code_coverage"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)
  
enable_testing()
add_library(ch7_code_coverage)
target_include_directories(ch7_code_coverage PUBLIC include)
target_compile_features(ch7_code_coverage PUBLIC cxx_std_11)
target_link_libraries(ch7_code_coverage INTERFACE --coverage)    
target_compile_options(ch7_code_coverage PUBLIC --coverage -O0 -g)
target_sources(ch7_code_coverage PRIVATE src/coverage_example/coverage_example.cpp)

add_executable(ch7_code_coverage_test src/coverage_test.cpp)
target_link_libraries(ch7_code_coverage_test ch7_code_coverage)
target_compile_features(ch7_code_coverage_test PRIVATE cxx_std_11)

target_compile_options(ch7_code_coverage_test PUBLIC --coverage -O0 -g)
add_test(NAME "code_coverage_test" COMMAND ch7_code_coverage_test)


