
# CMakeLists file for the Chapter 8 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch8_create_source_file_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate executing a custom command before building and executable"
  LANGUAGES CXX)

# A custom command that creates the main.cpp file for the executable target below
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/main.cpp 
  COMMAND cmake -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/WriteMain.cmake ${CMAKE_CURRENT_BINARY_DIR}/main.cpp
  COMMENT "Creating main.cpp"
  VERBATIM 
)

# As the target depends on the output of the custom command an implicit dependency is created
add_executable(
  ch8_create_source_file_example
  ${CMAKE_CURRENT_BINARY_DIR}/main.cpp
)
