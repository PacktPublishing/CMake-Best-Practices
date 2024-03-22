
# CMakeLists file for the Chapter 7 Example to show how catch2 test discovery can be used
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  "ch7_test_discovery_example"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate test discovery with Catch2 in CMake"
  LANGUAGES CXX)

# Fetch Catch2 from github and make it available 
include(FetchContent)
FetchContent_Declare(Catch2 
                     GIT_REPOSITORY https://github.com/catchorg/Catch2.git
                     GIT_TAG        v2.13.8)

FetchContent_MakeAvailable(Catch2)             
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/contrib/)
include(CTest)
include(Catch)

add_executable(ch7_test_discovery_example)
target_sources(ch7_test_discovery_example PRIVATE src/test.cpp)
target_link_libraries(ch7_test_discovery_example PRIVATE Catch2::Catch2)

# use the discovery function of catch2
catch_discover_tests(ch7_test_discovery_example)

