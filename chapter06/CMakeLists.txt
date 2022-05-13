# Top-level CMakeLists file for the Chapter 6 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

option(ENABLE_DOCUMENTATION "Enable documentation" OFF)

if(NOT ENABLE_DOCUMENTATION)
  message(STATUS "Documentation is disabled, excluded chapter 6 documentation examples")
  return()
endif()

project(
  "CMake Best Practices Chapter 6"
  VERSION 1.0
  DESCRIPTION
    "A collection of sample C++ applications and libraries to demonstrate documentation generation tool integrations"
  LANGUAGES CXX)

add_subdirectory(ex01_doxdocgen)
add_subdirectory(ex02_doxplantuml)
