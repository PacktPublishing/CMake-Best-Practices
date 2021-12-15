# Top-level CMakeLists file for the Chapter 3 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    chapter_3
    VERSION 1.0
    DESCRIPTION
        "A collection of sample C++ applications and libraries to demonstrate creating libraries and executables"
    LANGUAGES CXX
)

# Add subdirectories with examples
add_subdirectory(hello_world_standalone)
add_subdirectory(hello_shared_lib)
add_subdirectory(hello_static_lib)
add_subdirectory(hello_header_only)
add_subdirectory(hello_object_lib)

# add an example executable
add_executable(chapter3)
# add sources to the example executable
target_sources(chapter3 PRIVATE src/main.cpp)
# link libraries "hello" and "hello_header_only" to the example executable the
# libraries are described in the subdirectories
target_link_libraries(chapter3 PRIVATE ch3_hello_header_only ch3_hello_shared ch3_hello_object)
