
# CMakeLists file for the Chapter 8 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch8_custom_command_example
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate creating a post-build step using a custom command"
  LANGUAGES CXX)


add_executable(
  ch8_custom_command_example
  src/main.cpp)

add_custom_command(TARGET ch8_custom_command_example
  POST_BUILD
  COMMAND cmake -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/CreateSha256.cmake $<TARGET_FILE:ch8_custom_command_example> ${CMAKE_CURRENT_BINARY_DIR}/ch8_custom_command_example.sha256
  COMMENT "Creating hash for ch8_custom_command_example"  
)
