# ______________________________________________________
# CMakeLists file for the Chapter 1 example
#
# @file     CMakeLists.txt
# @author   Dominik Berner <dominik.berner@gmail.com>
# @date     05.09.2021
# 
# SPDX-License-Identifier: MIT
# ______________________________________________________

project(
  "CMake Tips and Tricks Chapter 1"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

add_executable(Chapter1)
target_sources(Chapter1 PRIVATE src/main.cpp)
