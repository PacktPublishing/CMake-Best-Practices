
# CMakeLists file for the Chapter 8 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch8_create_source_file_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate appending two custom commands"
  LANGUAGES CXX)


add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/main.cpp 
  COMMAND cmake -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/WriteMain.cmake ${CMAKE_CURRENT_BINARY_DIR}/main.cpp
  COMMENT "Creating main.cpp"
  VERBATIM 
)


add_executable(
  ch8_create_source_file_example
  ${CMAKE_CURRENT_BINARY_DIR}/main.cpp
)
