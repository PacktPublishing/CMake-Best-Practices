# Chapter12 -  creating a binary library for android
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.17)

project(
    androidlib
    VERSION 1.0.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating binaries for android"
    LANGUAGES CXX
)

# add the library target
add_library(androidlib)


# set properties for the target. VERSION set the library version to the project
# version * SOVERSION set the compatibility  version for the library to the
# major number of the version
set_target_properties(
    androidlib
    PROPERTIES VERSION ${PROJECT_VERSION}
               SOVERSION ${PROJECT_VERSION_MAJOR}
)

# add sources to the library target
target_sources(
    androidlib
    PRIVATE src/hello.cpp src/internal.cpp
)

# define the C++ standard needed to compile this library and make it visible to
# dependers
target_compile_features(
    androidlib
    PUBLIC cxx_std_17
)

# set the include directories
target_include_directories(
    androidlib
    PRIVATE src/androidlib
    PUBLIC include
)

install(TARGETS androidlib DESTINATION lib)