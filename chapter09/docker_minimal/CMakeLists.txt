
# CMakeLists file for the Chapter 9 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  ch9_simple_executable
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

add_executable(ch9_simple_executable src/main.cc)


