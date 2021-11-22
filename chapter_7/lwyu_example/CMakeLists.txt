
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_lwyu_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using clang-tidy on an executable"
  LANGUAGES CXX)

find_package(OpenSSL)

if(OpenSSL-NOTFOUND)
  message(STATUS "OpenSSL not found, disabling link what you use example")
else()
  option(ENABLE_LINK_WHAT_YOU_USE "Enable link what you use" ON)
  add_executable(ch7_lwyu_example)
  target_sources(ch7_lwyu_example PRIVATE src/main.cpp)
  target_link_libraries(ch7_lwyu_example OpenSSL::SSL)
  set_target_properties(ch7_lwyu_example PROPERTIES LINK_WHAT_YOU_USE ${ENABLE_LINK_WHAT_YOU_USE})  
endif()
