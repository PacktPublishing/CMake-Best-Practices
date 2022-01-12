# Top-level CMakeLists
# file for the CMake Best Practices book CMake example project
#
# SPDX-License-Identifier: MIT

# Specifies the minimum required CMake version to build this project (and
# subprojects) Subprojects may override this value by specifying another version
# requirement in their CMakeLists file (e.g. require a later version of CMake)
cmake_minimum_required(VERSION 3.21)

# The main project
project(
    "CMakeBestPractices"
    VERSION 1.0
    DESCRIPTION
        "The 'build-all' instructions for all examples for the book CMake Best Practices"
    LANGUAGES CXX
)
include(CTest)

# Set the default build type for single-config generators. The build type
# variable is still overridable from outside.
set(CMAKE_BUILD_TYPE
    "Debug"
    CACHE STRING "Default build type for single-config generators"
)

# Print generator type and build type (if applicable)
get_property(
    is_multi_config_generator GLOBAL
    PROPERTY GENERATOR_IS_MULTI_CONFIG
)
if(NOT is_multi_config_generator)
    message(STATUS "Using a single-config generator (${CMAKE_GENERATOR})")
    message(STATUS "Current build type is `${CMAKE_BUILD_TYPE}`")
else()
    message(STATUS "Using a multi-config generator (${CMAKE_GENERATOR})")
endif()

# Add chapter examples to root project
add_subdirectory(chapter_1)
add_subdirectory(chapter_2)
add_subdirectory(chapter_3)
add_subdirectory(chapter_4)
add_subdirectory(chapter_5)
add_subdirectory(chapter_6)
add_subdirectory(chapter_7)
# the chapter 10 examples are intended to be built standalone
# add_subdirectory(chapter_10) 