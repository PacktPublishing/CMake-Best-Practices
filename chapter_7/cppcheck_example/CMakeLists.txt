
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_cppcheck_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using cppcheck on an executable"
  LANGUAGES CXX)

find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)

if(CPPCHECK_EXECUTABLE)
  option(ENABLE_CPPCHECK "Enable cppcheck" ON)
  
  list(APPEND CPPCHECK_COMMAND "${CPPCHECK_EXECUTABLE}"
  "--enable=warning" 
  "--inconclusive"
  "--force"
  "--inline-suppr"
  #"--error-exitcode=1"
  )
  
  
endif()

add_executable(ch7_cppcheck_example)
target_sources(ch7_cppcheck_example PRIVATE src/main.cpp)
if (ENABLE_CPPCHECK)
  set_target_properties(ch7_cppcheck_example PROPERTIES CXX_CPPCHECK "${CPPCHECK_COMMAND}")    
endif()
