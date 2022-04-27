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

if(WIN32)
  # In Windows, lld-link does not accept -fsanitize=fuzzer argument, so we have to manually pass
  # the ASAN and libFuzzer libraries to the linker.
  # In order to do that, we have to discover the LLVM path first.
  get_filename_component(COMPILER_BIN_PATH "${CMAKE_CXX_COMPILER}" DIRECTORY)
  get_filename_component(COMPILER_PATH "${COMPILER_BIN_PATH}/.." ABSOLUTE)
 
  find_file(lib_asan_preinit NAMES "clang_rt.asan-preinit-x86_64.lib" PATHS "${COMPILER_PATH}/lib/clang/*/lib/windows" NO_CACHE NO_DEFAULT_PATHS REQUIRED)
  find_file(lib_asan NAMES "clang_rt.asan-x86_64.lib" PATHS "${COMPILER_PATH}/lib/clang/*/lib/windows" NO_CACHE NO_DEFAULT_PATHS REQUIRED)
  find_file(lib_asan_cxx NAMES "clang_rt.asan_cxx-x86_64.lib" PATHS "${COMPILER_PATH}/lib/clang/*/lib/windows" NO_CACHE NO_DEFAULT_PATHS REQUIRED)
  find_file(lib_fuzzer NAMES "clang_rt.fuzzer-x86_64.lib" PATHS "${COMPILER_PATH}/lib/clang/*/lib/windows" NO_CACHE NO_DEFAULT_PATHS REQUIRED)
  
  # Pass link flags to linker to enable libFuzzer for clang
  target_link_libraries(ch11_ex01_libfuzzer_fuzz PRIVATE ${lib_asan_preinit} ${lib_asan} ${lib_asan_cxx} ${lib_fuzzer})
  # cmake -G "Visual Studio 17" -T ClangCL -S . -B build 
  # cmake --build .\build\ --target ch11_ex01_libfuzzer_fuzz
else()
  # Pass link flags to linker to enable libFuzzer for clang
  target_link_libraries(ch11_ex01_libfuzzer_fuzz PRIVATE -fsanitize=fuzzer)
endif()
