
# CMakeLists file for the Chapter 1 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch12_emulator_example
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

include(CTest)  

add_executable(ch12_emulator_example)
target_sources(ch12_emulator_example PRIVATE src/main.cpp)

add_test(NAME emulator_test COMMAND ch12_emulator_example)

