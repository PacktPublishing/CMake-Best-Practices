# Top-level CMakeLists file for the Chapter 14 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    chapter_14
    VERSION 1.0
    DESCRIPTION
        "Examples for chapter 14 of the CMake Best Practices book"
    LANGUAGES CXX
)

add_subdirectory(unity_build)
add_subdirectory(unity_build_group)
add_subdirectory(precompiled_headers)