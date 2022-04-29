# Top-level CMakeLists file for the Chapter 10 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    chapter_13
    VERSION 1.0
    DESCRIPTION
        "Examples for chapter 13 of the CMake Best Practices book"
    LANGUAGES CXX
)

add_subdirectory(ex01_git_utility)
add_subdirectory(ex02_envfile_utility)
add_subdirectory(ex03_hadouken)