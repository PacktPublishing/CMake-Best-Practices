# CMakeLists file for the Chapter 13 Example nr. 03:
# Using external CMake modules
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch13_ex03_hadouken
  VERSION 1.0
  DESCRIPTION "Chapter 13 Example 03, external CMake modules (hadouken) example"
  LANGUAGES CXX)

include(FetchContent)

# Declare hadouken dependency details.
FetchContent_Declare(hadouken
    GIT_REPOSITORY https://github.com/mustafakemalgilor/hadouken.git
    GIT_TAG        7d0447fcadf8e93d25f242b9bb251ecbcf67f8cb
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/.hadouken"
)

# Fetch hadouken
FetchContent_MakeAvailable(hadouken)

# Add hadouken module directory to CMake module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/.hadouken/cmake/modules/)

# Include some CMake modules provided by the Hadouken
include(misc/Log)
include(misc/Utility)
include(core/MakeCompilationUnit)
include(core/MakeTarget)

# Create an executable target by using Hadouken's make_target() utility function
make_target(TYPE EXECUTABLE)