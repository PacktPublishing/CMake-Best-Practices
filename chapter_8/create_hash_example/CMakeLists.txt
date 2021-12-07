
# CMakeLists file for the Chapter 8 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch8_generate_hash_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate creation of a custom target"
  LANGUAGES CXX)

find_program(CLANG_FORMAT_EXECUTABLE clang-format)

add_executable(
  ch8_generate_hash_example
  src/main.cpp)

add_custom_command(OUTPUT hash_example.md5 
                   COMMAND cmake -E md5sum $<TARGET_FILE:ch8_generate_hash_example> > ${CMAKE_CURRENT_BINARY_DIR}/hash_example.md5
                   COMMENT "Creating MD5 hash for $<TARGET_FILE:ch8_generate_hash_example>"
                   VERBATIM 
)

find_program(GZIP_EXE gzip)

if(GZIP_EXE)
  message(STATUS "GZIP found, compressing hash")
  add_custom_command(OUTPUT hash_example.md5 hash_example.md5.gz
  COMMAND ${GZIP_EXE} -k -f ${CMAKE_CURRENT_BINARY_DIR}/hash_example.md5
  APPEND) 
endif()



add_custom_target(ch8_compute_md5 ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/hash_example.md5)

