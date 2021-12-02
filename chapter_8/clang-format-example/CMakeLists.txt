
# CMakeLists file for the Chapter 1 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch8_clang_format_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate creating a pre-build step using a custom command"
  LANGUAGES CXX)

find_program(CLANG_FORMAT_EXECUTABLE clang-format)

add_executable(
  ch8_clang_format_example
  src/main.cpp)

if(CLANG_FORMAT_EXECUTABLE-NOTFOUND)
  message(STATUS "clang-format not found, skipping clang-format step")
else()
get_target_property(CH8_CLANG_FORMAT_EXAMPLE_SOURCES ch8_clang_format_example SOURCES)

add_custom_command(TARGET ch8_clang_format_example
  PRE_BUILD
  COMMAND ${CLANG_FORMAT_EXECUTABLE} -i -style=LLVM ${CH8_CLANG_FORMAT_EXAMPLE_SOURCES}
  COMMENT "Formatting C++ source files using clang-format"
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()
