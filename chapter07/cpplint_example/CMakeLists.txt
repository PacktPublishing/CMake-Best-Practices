
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  "ch7_cpplint_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using cppcheck on an executable"
  LANGUAGES CXX)

find_program(CPPLINT_EXECUTABLE NAMES cppcheck)

if(CPPLINT_EXECUTABLE)
  option(ENABLE_CPPLINT "Enable cppcheck" ON)
  message(STATUS "CPPlint enabled")
endif()

set(CPPLINT_COMMAND "")

if(ENABLE_CPPLINT)
  list(APPEND CPPLINT_COMMAND "${CPPLINT_EXECUTABLE}")
endif()

add_executable(ch7_cpplint_example)
target_sources(ch7_cpplint_example PRIVATE src/main.cpp)
set_target_properties(ch7_cpplint_example PROPERTIES CXX_CPPLINT "${CPPLINT_COMMAND}")    

