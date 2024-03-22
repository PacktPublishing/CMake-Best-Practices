
# Chapter 8 example to illustrate creation of a custom targert
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  "ch8_custom_target_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate creation of a custom target"
  LANGUAGES CXX)

# create a list to be used in the custom command
list(APPEND MYLIST "A" "B" "C")

# Adds a custom target that prints out a message to stdout.
# Adding the ALL keyword adds the target to the "all" meta-target
# COMMAND_EXPAND_LIST causes the variable ${MYLIST} to be expanded as a string.
# if this is not set B and C will be treated as separate commands
add_custom_target(ch8_echo_target ALL 
                  COMMAND cmake -E echo "Hello from a custom target in chapter 8 ${MYLIST}"
                  COMMAND_EXPAND_LISTS)
