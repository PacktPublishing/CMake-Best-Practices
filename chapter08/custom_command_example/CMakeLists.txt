
# Chapter 8 example to illustrate the usage of a post build step
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch8_custom_command_example
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate creating a post-build step using a custom command"
  LANGUAGES CXX)

# define a exectuable target
add_executable(
  ch8_custom_command_example
  src/main.cpp)

# add a custom command as post build action to the executable target. 
# the command creates a sha256 hash of the output file created by the executable target by using 
# cmake in script mode 
add_custom_command(TARGET ch8_custom_command_example
  POST_BUILD
  COMMAND cmake -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/CreateSha256.cmake $<TARGET_FILE:ch8_custom_command_example> ${CMAKE_CURRENT_BINARY_DIR}/ch8_custom_command_example.sha256
  COMMENT "Creating hash for ch8_custom_command_example"  
)
