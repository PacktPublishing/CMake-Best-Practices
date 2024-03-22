#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    an_obscure_lib
    VERSION 1.0.0
    DESCRIPTION
        "An example project to compile to use with the find_module example"
    LANGUAGES CXX
)

# add the library target
add_library(obscure SHARED)

# set properties for the target. VERSION set the library version to the project
# version * SOVERSION set the compatibility  version for the library to the
# major number of the version
set_target_properties(
    obscure
    PROPERTIES VERSION ${PROJECT_VERSION}
               SOVERSION ${PROJECT_VERSION_MAJOR}
)

# add sources to the library target
target_sources(
    obscure
    PRIVATE src/obscure.cpp src/internal.cpp
)

# define the C++ standard needed to compile this library and make it visible to
# dependers
target_compile_features(
    obscure
    PUBLIC cxx_std_17
)

# set the include directories
target_include_directories(
    obscure
    PRIVATE src/obscure
    PUBLIC include
)

# make all symbols visible for demonstration purposes
set_property(
    TARGET obscure
    PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS TRUE
)
