
# CMakeLists file for the Chapter 7. Example to show how to enable link what you use
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_lwyu_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using lwyu on an executable"
  LANGUAGES CXX)

find_package(OpenSSL)

# only enable lwyu if openSSL is found and only for GCC and CLang
if(OpenSSL-NOTFOUND)
  message(STATUS "OpenSSL not found, disabling link what you use example")

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  option(ENABLE_LINK_WHAT_YOU_USE "Enable link what you use" ON)
  add_executable(ch7_lwyu_example)
  target_sources(ch7_lwyu_example PRIVATE src/main.cpp)
  target_link_libraries(ch7_lwyu_example OpenSSL::SSL)
  set_target_properties(ch7_lwyu_example PROPERTIES LINK_WHAT_YOU_USE ${ENABLE_LINK_WHAT_YOU_USE})  
else()
  message(STATUS "Your compiler ${CMAKE_CXX_COMPILER_ID} does not support link what you use, disabling link what you use example")
endif()
