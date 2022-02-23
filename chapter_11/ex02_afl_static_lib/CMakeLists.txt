# CMakeLists file for the Chapter 11 Example nr. 02:
# Static library fuzzing with AFL++
#
# SPDX-License-Identifier: MIT

project(
  ch11_ex02_afl_static_lib
  VERSION 1.0
  DESCRIPTION "Chapter 11 Example 02, fuzzing of a static library with AFL++"
  LANGUAGES CXX)

# Define an executable target named `ch11_ex02_afl_static_lib` 
add_library(ch11_ex02_afl_static_lib STATIC)
# Specify source files for target named `ch11_ex02_afl_static_lib`
target_sources(ch11_ex02_afl_static_lib PRIVATE src/uri_helper.cpp)
# Specify the include directories for the target named `ch11_ex02_afl_static_lib`
target_include_directories(ch11_ex02_afl_static_lib PUBLIC include)
# Request compile features for target named `ch11_ex02_afl_static_lib`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch11_ex02_afl_static_lib PRIVATE cxx_std_11)
# Include the fuzzing target
add_subdirectory(fuzz)