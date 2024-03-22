# CMakeLists file for the Chapter 10 Example nr. 01: 
# External Dependencies in Superbuild
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  ch10_ex02_external_deps_with_extproject
  VERSION 1.0
  DESCRIPTION "Chapter 10 Example 02, External Dependencies in Superbuild (with ExternalProject_Add)"
  LANGUAGES CXX)

# Since ExternalProject_Add makes the content available in cmake build step, there is 
# no clean way to utilize FindPackage(), since FindPackage() requires package files to be
# present in the configure stage. For such scenarios, it is better to stick with FetchContent
# since it allows you to fetch the content in configure stage.
include(superbuild.cmake)

# A simple unit test target
add_executable(ch10_ex02_tests)
target_sources(ch10_ex02_tests PRIVATE src/tests.cpp)
target_link_libraries(ch10_ex02_tests PRIVATE catch2)



