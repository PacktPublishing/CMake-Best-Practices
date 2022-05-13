# Chapter3- example illustrating how to create a shared library
# Additionally the example shows how to set a postfix for debug libraries and 
# how to handle symbol visibilities for shared libraries
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.17)

project(
    ch3_hello_shared
    VERSION 1.0.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating executables and libraries in CMake"
    LANGUAGES CXX
)

# set the postfix "d" for the resulting .so or .dll files when building the
# library in debug mode
set(CMAKE_DEBUG_POSTFIX
    d
)

# add the library target
add_library(ch3_hello_shared SHARED)

# set properties for the target. VERSION set the library version to the project
# version * SOVERSION set the compatibility  version for the library to the
# major number of the version
set_target_properties(
    ch3_hello_shared
    PROPERTIES VERSION ${PROJECT_VERSION}
               SOVERSION ${PROJECT_VERSION_MAJOR}
)

# add sources to the library target
target_sources(
    ch3_hello_shared
    PRIVATE src/hello.cpp src/internal.cpp
)

# define the C++ standard needed to compile this library and make it visible to
# dependers
target_compile_features(
    ch3_hello_shared
    PUBLIC cxx_std_17
)

# set the include directories
target_include_directories(
    ch3_hello_shared
    PRIVATE src/ch3_hello_shared
    PUBLIC include
)

# if using limited visibility, set CXX_VISIBILILTY_PRESET to "hidden"
include(GenerateExportHeader)
set_property(
    TARGET ch3_hello_shared
    PROPERTY CXX_VISIBILITY_PRESET "hidden"
)
# Hide inlined functions by default, reducing the size of the library
set_property(
    TARGET ch3_hello_shared
    PROPERTY VISIBILITY_INLINES_HIDDEN TRUE
)
# this command generates a header file in the CMAKE_CURRENT_BINARY_DIR which
# sets the visibility attributes according to the compiler settings
generate_export_header(
    ch3_hello_shared
    EXPORT_FILE_NAME
    export/hello/export_hello.hpp
)
# Add CMAKE_CURRENT_BINARY_DIR to the include path so the generated header can
# be found
target_include_directories(
    ch3_hello_shared
    PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/export"
)

# An alternative but not recomended way export the symbols is to use
# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE) Which exports all dll symbols by
# default
