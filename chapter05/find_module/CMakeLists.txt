# Chapter 5 - CMakeLists to show how find-modules work
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    ch5_find_module_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate how find-modules work"
    LANGUAGES CXX
)

# The following example will look for a pre-built library in the folder ${CMAKE_CURRENT_BINARY_DIR}/dep. To use it build the project located in `dep_source`
# first and install it in the directory `dep` of the current source tree

# Tell CMake where to look for find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# try to find the package obscure see the file cmake/FindObscure.cmake for the innner workings
find_package(Obscure QUIET)

if(NOT Obscure_FOUND)
    message(STATUS "Prebuilt library 'obscure' not found, skipping find module example")
    return()
endif()

# Create a target to build an executable
add_executable(ch5_find_module_example)
target_link_libraries(ch5_find_module_example PRIVATE Obscure::Obscure)
# set the c++ version required

target_compile_features(
    ch5_find_module_example
    PRIVATE cxx_std_11
)
# Add source files to 'hello_world' target
target_sources(
    ch5_find_module_example
    PRIVATE src/main.cpp
)
