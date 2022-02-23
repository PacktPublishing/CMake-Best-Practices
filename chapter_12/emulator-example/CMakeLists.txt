
# CMakeLists file for the Chapter 1 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch12_emulator_example
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

add_executable(chapter1)
target_sources(chapter1 PRIVATE src/main.cpp)

