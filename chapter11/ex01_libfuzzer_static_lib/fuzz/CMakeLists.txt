# CMakeLists file for the Chapter 11 Example nr. 01:
# Driver application
#
# SPDX-License-Identifier: MIT

project(
  ch11_ex01_libfuzzer_fuzz
  VERSION 1.0
  DESCRIPTION "Chapter 11 Example 01, fuzzing of a static library with libfuzzer, driver application"
  LANGUAGES CXX)

if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "ch11_ex01_libfuzzer_fuzz requires clang compiler. example will not be built.")
    return()
endif()

# Define an executable target named `ch11_ex01_libfuzzer_fuzz` 
add_executable(ch11_ex01_libfuzzer_fuzz)
# Specify source files for target named `ch11_ex01_libfuzzer_fuzz`
target_sources(ch11_ex01_libfuzzer_fuzz PRIVATE fuzz_library.cpp)
# Request compile features for target named `ch11_ex01_libfuzzer_fuzz`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch11_ex01_libfuzzer_fuzz PRIVATE cxx_std_11)
# link against the fuzzing target
target_link_libraries(ch11_ex01_libfuzzer_fuzz PRIVATE ch11_ex01_libfuzzer_static)
# Pass compile flags to enable libFuzzer for clang
target_compile_options(ch11_ex01_libfuzzer_fuzz PRIVATE -fsanitize=fuzzer)
# Pass link flags to linker to enable libFuzzer for clang
target_link_libraries(ch11_ex01_libfuzzer_fuzz PRIVATE -fsanitize=fuzzer)