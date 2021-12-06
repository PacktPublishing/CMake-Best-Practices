
# CMakeLists file for the Chapter 8 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch8_custom_target_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate creation of a custom target"
  LANGUAGES CXX)

list(APPEND MYLIST "A" "B" "C")

add_custom_target(ch8_echo_target ALL cmake -E echo "Hello from a custom target in chapter 8 ${MYLIST}" COMMAND_EXPAND_LISTS)
