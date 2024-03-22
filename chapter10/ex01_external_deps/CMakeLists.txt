# CMakeLists file for the Chapter 10 Example nr. 01: 
# External Dependencies in Superbuild
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  ch10_ex01_external_deps
  VERSION 1.0
  DESCRIPTION "Chapter 10 Example 01, External Dependencies in Superbuild"
  LANGUAGES CXX)

option(CH10_EX01_USE_SUPERBUILD "Enable superbuild for chapter 10, example 01"  OFF)

if(CH10_EX01_USE_SUPERBUILD)
  include(superbuild.cmake)
else()
  # User decided to not to use superbuild. We have to discover the dependencies
  # from the current environment as usual.
  find_package(GTest 1.10.0 REQUIRED)
  find_package(benchmark 1.6.1 REQUIRED)
endif()

# A simple unit test target
add_executable(ch10_ex01_tests)
target_sources(ch10_ex01_tests PRIVATE src/tests.cpp)
target_link_libraries(ch10_ex01_tests PRIVATE GTest::Main)

# A simple microbenchmark target
add_executable(ch10_ex01_benchmarks)
target_sources(ch10_ex01_benchmarks PRIVATE src/benchmarks.cpp)
target_link_libraries(ch10_ex01_benchmarks PRIVATE benchmark::benchmark)


