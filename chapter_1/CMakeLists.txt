# Top-level CMakeLists file for the Chapter 3 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    "Chapter_1"
    VERSION 1.0
    DESCRIPTION
        "Examples for chapter 1 of the CMake tips and tricks book"
    LANGUAGES CXX
)

# Add subdirectories with a simple executable
add_subdirectory(simple_executable)
