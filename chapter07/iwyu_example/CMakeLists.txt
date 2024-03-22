
# CMakeLists file for the Chapter 7. Example to show how to use include what you use
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  "ch7_iwyu_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using iwyu on an executable"
  LANGUAGES CXX)

# if the iwyu program is found it is configured
find_program(INCLUDE_WHAT_YOU_USE_EXECUTABLE NAMES include-what-you-use iwyu)

if(INCLUDE_WHAT_YOU_USE_EXECUTABLE)
  option(ENABLE_INCLUDE_WHAT_YOU_USE "Enable iwyu" ON)
    
  list(APPEND INCLUDE_WHAT_YOU_USE_COMMAND "${INCLUDE_WHAT_YOU_USE_EXECUTABLE}"
  "-Xiwyu"
  "any"
  "-Xiwyu"
  "iwyu"
  "-Xiwyu"
  "-I ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES}"
  )
      
endif()

add_executable(ch7_iwyu_example)
target_sources(ch7_iwyu_example PRIVATE src/main.cpp)
if (ENABLE_INCLUDE_WHAT_YOU_USE)
  message(STATUS "Enabling IWYU for example ${INCLUDE_WHAT_YOU_USE_COMMAND}")
  set_target_properties(ch7_iwyu_example PROPERTIES CXX_INCLUDE_WHAT_YOU_USE "${INCLUDE_WHAT_YOU_USE_COMMAND}")    
endif()
