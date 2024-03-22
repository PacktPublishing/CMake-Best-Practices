# Top-level CMakeLists file for the Chapter 10 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    chapter_10
    VERSION 1.0
    DESCRIPTION
        "Examples for chapter 10 of the CMake Best Practices book"
    LANGUAGES CXX
)

add_subdirectory(ex01_external_deps)
add_subdirectory(ex02_external_deps_with_extproject)