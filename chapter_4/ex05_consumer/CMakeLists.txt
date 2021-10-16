# CMakeLists file for the Chapter 4 Example nr. 05: 
# Example CMake consumer for Config-file package
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch4_ex05_consumer
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 05, Out ot project config-file package consumer"
  LANGUAGES CXX)

if(NOT PROJECT_IS_TOP_LEVEL)
  message(FATAL_ERROR "The chapter-4, ex05_consumer project is intended to be a standalone, top-level project. Do not vendor this directory.")
endif()

##################################################################################
# IMPORTANT NOTE: If ch4_ex05_lib is installed on a non-default install prefix
# this project must be configured with -DCMAKE_PREFIX_PATH:STRING=<install prefix>
# variable. This enables find_package() to discover the package even though it is 
# installed to a custom prefix. 
##################################################################################

# Let's find our package. We're explicitly specifying CONFIG argument
# to not to search for MODULE packages. CMake will fail if package is not present
# since REQUIRED argument is given. Also, we're explicitly requesting major version
# of 1. We are able to do this since we've provided a <project>-config-version.cmake file too.
# The packages with no -config-version.cmake file are not considered by find_package() when version
# is specified.
find_package(ch4_ex05_lib 1 CONFIG REQUIRED)

# Define the executable that will consume the ch4_ex05_lib package
add_executable(ch4_ex05_consumer src/main.cpp)

# Set the required C++ standard for the target
target_compile_features(ch4_ex05_consumer PRIVATE cxx_std_11)

# Link executable to ch4_ex05_lib package found by find_package() before. Target is under 
# `ch4_ex05_lib::` namespace since export is made using that namespace. 
target_link_libraries(ch4_ex05_consumer PRIVATE ch4_ex05_lib::ch4_ex05_lib)