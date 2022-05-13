# CMakeLists file for the Chapter 11 Example nr. 01:
# Static library fuzzing with libfuzzer
#
# SPDX-License-Identifier: MIT

project(
  ch11_ex01_libfuzzer_static
  VERSION 1.0
  DESCRIPTION "Chapter 11 Example 01, fuzzing of a static library with libfuzzer"
  LANGUAGES CXX)

# Define an executable target named `ch11_ex01_libfuzzer_static` 
add_library(ch11_ex01_libfuzzer_static STATIC)
# Specify source files for target named `ch11_ex01_libfuzzer_static`
target_sources(ch11_ex01_libfuzzer_static PRIVATE src/library.cpp)
# Specify the include directories for the target named `ch11_ex01_libfuzzer_static`
target_include_directories(ch11_ex01_libfuzzer_static PUBLIC include)
# Request compile features for target named `ch11_ex01_libfuzzer_static`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch11_ex01_libfuzzer_static PRIVATE cxx_std_11)
# Include the fuzzing target
add_subdirectory(fuzz)