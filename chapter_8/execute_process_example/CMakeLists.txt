
# CMakeLists file for the Chapter 8 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch8_execute_process_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate usage of execute_process"
  LANGUAGES CXX)


find_package(Git)
if(NOT Git_FOUND)
  message(STATUS "Git command not found; skipping building the example for execute process")
  return()
endif()



execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
                OUTPUT_VARIABLE GIT_REVISION 
                OUTPUT_STRIP_TRAILING_WHITESPACE
                COMMAND_ERROR_IS_FATAL ANY
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(
  ch8_execute_process_example
  src/main.cpp)

target_compile_definitions(ch8_execute_process_example PRIVATE VERSION=\"${GIT_REVISION}\")