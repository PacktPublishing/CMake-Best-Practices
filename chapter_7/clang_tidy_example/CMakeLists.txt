
# CMakeLists file for the Chapter 7. Example to show how to use clang tidy
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_clang_tidy_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using clang-tidy on an executable"
  LANGUAGES CXX)

if(NOT CMAKE_CXX_CLANG_TIDY)
  find_program(CLANG_TIDY_EXECUTABLE NAMES clang-tidy)

  if(CLANG_TIDY_EXECUTABLE)
    option(ENABLE_CLANG_TIDY "Enable CLANG_TIDY" ON)
      
    list(APPEND CLANG_TIDY_COMMAND "${CLANG_TIDY_EXECUTABLE}"
    "-checks=-*,modernize-use-nullptr,-extra-arg=-std=c++17")

  endif()
  
endif()

add_executable(ch7_clang_tidy_example)
target_sources(ch7_clang_tidy_example PRIVATE src/main.cpp)
target_compile_features(ch7_clang_tidy_example PRIVATE cxx_std_17)
if (ENABLE_CLANG_TIDY)
  set_target_properties(ch7_clang_tidy_example PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")    
endif()
