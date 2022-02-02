# Top-level CMakeLists file for the Chapter 12 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    "Chapter_12"
    VERSION 1.0
    DESCRIPTION
        "A collection of sample C++ projects to demonstrate testing, code coverage and static code analysis"
    LANGUAGES CXX
)

add_subdirectory(check_source_compiles)
