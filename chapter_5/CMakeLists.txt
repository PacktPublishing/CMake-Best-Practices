# Top-level CMakeLists file for the Chapter 5 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    "Chapter_5"
    VERSION 1.0
    DESCRIPTION
        "A collection of sample C++ projects to demonstrate using external dependencies"
    LANGUAGES CXX
)

add_subdirectory(find_package_example)
add_subdirectory(find_module)
add_subdirectory(fetch_content_example)
add_subdirectory(external_project_example)
add_subdirectory(conan_example)