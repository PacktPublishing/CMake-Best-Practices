# Chapter3-  creating a binary library for static linking
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.17)

project(
    ioslib
    VERSION 1.0.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating executables and libraries in CMake"
    LANGUAGES CXX
)

# add the library target
add_library(ioslib)

set_target_properties(
    ioslib
    PROPERTIES OUTPUT_NAME hello
)


# set properties for the target. VERSION set the library version to the project
# version * SOVERSION set the compatibility  version for the library to the
# major number of the version
set_target_properties(
    ioslib
    PROPERTIES VERSION ${PROJECT_VERSION}
               SOVERSION ${PROJECT_VERSION_MAJOR}
)

# add sources to the library target
target_sources(
    ioslib
    PRIVATE src/hello.cpp src/internal.cpp
)

# define the C++ standard needed to compile this library and make it visible to
# dependers
target_compile_features(
    ioslib
    PUBLIC cxx_std_17
)

# set the include directories
target_include_directories(
    ioslib
    PRIVATE src/ioslib
    PUBLIC include
)

install(TARGETS ioslib DESTINATION lib)