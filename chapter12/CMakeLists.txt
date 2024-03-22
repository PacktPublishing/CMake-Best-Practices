# Top-level CMakeLists file for the Chapter 12 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    "Chapter_12"
    VERSION 1.0
    DESCRIPTION
        "A collection of sample C++ projects to demonstrate cross-compiling, toolchains and toolchain checks"
    LANGUAGES CXX
)
# The examples ion android-example and iOS_example are to be used standalone with the 
# the respective SDKs and NDKs
add_subdirectory(check_source_compiles)
add_subdirectory(check_push_pop)
