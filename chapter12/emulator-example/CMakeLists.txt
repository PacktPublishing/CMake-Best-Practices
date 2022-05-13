
# Chapter 12 example to use with the emulator when cross compiled
# This example is supposed to be compiled with the `arm64.toolchain.cmake` toolchain 
# in the same directory, which defines the qemu command to run the test inside the emulator
# 
# check the github action workflow cross-compiling.yml 
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch12_emulator_example
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

# enable testing
include(CTest)

# define an executable target
add_executable(ch12_emulator_example)
target_sources(ch12_emulator_example PRIVATE src/main.cpp)


add_test(NAME emulator_test COMMAND ch12_emulator_example)

