# CMakeLists file for the Chapter 11 Example nr. 02:
# Driver application
#
# SPDX-License-Identifier: MIT

project(
  ch11_ex02_afl_fuzz
  VERSION 1.0
  DESCRIPTION "Chapter 11 Example 02, fuzzing of a static library with AFL++, driver application"
  LANGUAGES CXX)

if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "ch11_ex02_afl_fuzz requires GNU compiler. example will not be built.")
    return()
endif()

# Define an executable target named `ch11_ex02_afl_fuzz` 
add_executable(ch11_ex02_afl_fuzz)
# Specify source files for target named `ch11_ex02_afl_fuzz`
target_sources(ch11_ex02_afl_fuzz PRIVATE fuzz_uri_helper.cpp)
# Request compile features for target named `ch11_ex02_afl_fuzz`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch11_ex02_afl_fuzz PRIVATE cxx_std_11)
# link against the fuzzing target
target_link_libraries(ch11_ex02_afl_fuzz PRIVATE ch11_ex02_afl_static_lib)