
# Chapter 8 example to illustrate using a custom target with an implicit dependency on another target
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch8_generate_hash_using_a_target
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate creation of a custom target that implicitely depends on another one"
  LANGUAGES CXX)

# create a custom target that uses cmake in script mode to create a sha256 hash of the output file created by another target
# using the $<TARGET_FILE: generator expression implcitely adds the dependency vetween the targets. 
# the ALL keyword adds the custom target to the ALL meta-target
add_custom_target(ch8_create_hash ALL 
                  COMMAND cmake -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/CreateSha256.cmake $<TARGET_FILE:ch8_generate_hash_using_a_target> ${CMAKE_CURRENT_BINARY_DIR}/hash_example.sha256
                  COMMENT "Creating sha256 hash using a custom target $<TARGET_FILE:ch8_generate_hash_using_a_target>"
)

add_executable(
  ch8_generate_hash_using_a_target
  src/main.cpp)
