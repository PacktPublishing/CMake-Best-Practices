# Top-level CMakeLists file for the Chapter 11 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    chapter_11
    VERSION 1.0
    DESCRIPTION
        "Examples for chapter 11 of the CMake Best Practices book"
    LANGUAGES CXX
)

add_subdirectory(ex01_libfuzzer_static_lib)
add_subdirectory(ex02_afl_static_lib)