# Chapter3-  Illustriating how to create a static library
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.17)

project(
    ch3_hello_static
    VERSION 1.0.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating executables and libraries in CMake"
    LANGUAGES CXX
)

# add the library target
add_library(ch3_hello_static STATIC)

# Set the output of the target to `hello` so it will be saved as hello.dll on windows
# and libhello.a on linux
set_target_properties(
    ch3_hello_static
    PROPERTIES OUTPUT_NAME hello
)


# set properties for the target. VERSION set the library version to the project
# version * SOVERSION set the compatibility  version for the library to the
# major number of the version
set_target_properties(
    ch3_hello_static
    PROPERTIES VERSION ${PROJECT_VERSION}
               SOVERSION ${PROJECT_VERSION_MAJOR}
)

# add sources to the library target
target_sources(
    ch3_hello_static
    PRIVATE src/hello.cpp src/internal.cpp
)

# define the C++ standard needed to compile this library and make it visible to
# dependers
target_compile_features(
    ch3_hello_static
    PUBLIC cxx_std_17
)

# set the include directories
target_include_directories(
    ch3_hello_static
    PRIVATE src/ch3_hello_static
    PUBLIC include
)
