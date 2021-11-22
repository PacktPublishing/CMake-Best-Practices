
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_micro_benchmark_test"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate micro benchmarking in CMake"
  LANGUAGES CXX)

## use catch2 for micro benchmarking
include(FetchContent)
FetchContent_Declare(Catch2 
                     GIT_REPOSITORY https://github.com/catchorg/Catch2.git
                     GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)             
  

add_executable(ch7_micro_benchmark_test)
target_sources(ch7_micro_benchmark_test PRIVATE src/benchmark.cpp)
target_link_libraries(ch7_micro_benchmark_test PRIVATE Catch2::Catch2)
target_compile_options(
  ch7_micro_benchmark_test
  PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/DCATCH_CONFIG_ENABLE_BENCHMARKING>
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-DCATCH_CONFIG_ENABLE_BENCHMARKING>
)

add_test(NAME micro_benchmark_test COMMAND ch7_micro_benchmark_test -r xml -o ${CMAKE_CURRENT_BINARY_DIR}/micro_benchmark_test.xml
CONFIGURATIONS Release)

