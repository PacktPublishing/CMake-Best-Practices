
# Chapter 8 example to illustrate how configure_file works
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch8_configure_file_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate usage of configure_file and execute_process"
  LANGUAGES CXX)

# Search git command as it is needed for the example
find_package(Git)
if(NOT Git_FOUND)
  message(STATUS "Git command not found; skipping building the example for execute process")
  return()
endif()

# Make writing the version optional
option(GIT_VERSION_ENABLE "Define the git version in a header file" ON)

if(GIT_VERSION_ENABLE)
# execute a git command at configuration time and store teh results in the GIT_REVISION variable
# strip any trailing whitespaces and threat any non-zero return value as fatal error
execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
                OUTPUT_VARIABLE GIT_REVISION 
                OUTPUT_STRIP_TRAILING_WHITESPACE
                COMMAND_ERROR_IS_FATAL ANY
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# replace the placeholder in the version.h.in file with the variable GIT_REVISION
configure_file(version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/version.h @ONLY)

# create an executable target that uses the generated file
add_executable(
  ch8_configure_file_example
  src/main.cpp)

