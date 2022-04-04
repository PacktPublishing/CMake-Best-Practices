
# CMakeLists file for the Chapter 8 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch8_create_tar_archive_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate appending two custom commands"
  LANGUAGES CXX)

find_program(CLANG_FORMAT_EXECUTABLE clang-format)

add_executable(
  ch8_create_tar_archive_example
  src/main.cpp)

add_custom_command(OUTPUT ch8_create_tar_archive_example.tar.gz
                  COMMAND cmake -E tar czf ${CMAKE_CURRENT_BINARY_DIR}/ch8_create_tar_archive_example.tar.gz $<TARGET_FILE:ch8_create_tar_archive_example>
                  COMMENT "Creating Archive for ch8_create_tar_archive_example"
                  VERBATIM 
)

add_custom_command(OUTPUT ch8_create_tar_archive_example.tar.gz
  COMMAND cmake -E tar czf ${CMAKE_CURRENT_BINARY_DIR}/ch8_create_tar_archive_example.tar.gz ${CMAKE_CURRENT_SOURCE_DIR}/SomeFile.txt
  APPEND
) 

add_custom_target(ch8_create_archive ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/ch8_create_tar_archive_example.tar.gz)

