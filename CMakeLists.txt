# ______________________________________________________ Top-level CMakeLists
# file for the CMake Tips and Tricks book CMake example project
#
# @file     CMakeLists.txt @author   Dominik Berner <dominik.berner@gmail.com>
# Mustafa Kemal GILOR <mustafagilor@gmail.com> @date     05.09.2021
#
# SPDX-License-Identifier: MIT
# ______________________________________________________

# Specifies the minimum required CMake version to build this project (and
# subprojects) Subprojects may override this value by specifying another version
# requirement in their CMakeLists file (e.g. require a later version of CMake)
cmake_minimum_required(VERSION 3.21)

# The main project
project(
  "CMake Tips and Tricks"
  VERSION 1.0
  DESCRIPTION
    "The 'build-all' instructions for all examples for the book CMake tips and tricks"
  LANGUAGES CXX)

# Set build type to "Debug" if not set.
if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Print current build type
message("Current build type ${CMAKE_BUILD_TYPE}")

# Add chapter examples to root project
add_subdirectory(chapter_1)
add_subdirectory(chapter_2)
add_subdirectory(chapter_3)
