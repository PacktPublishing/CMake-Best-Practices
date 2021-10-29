# CMakeLists creating a simple executable that links to a system library
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    fetch_content_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate fetching external content"
    LANGUAGES CXX
)
include(FetchContent)

FetchContent_Declare(
  bertrand
  GIT_REPOSITORY https://github.com/bernedom/bertrand.git
  GIT_TAG 0.0.17)

FetchContent_MakeAvailable(bertrand)

# # disable debugging again set(CMAKE_FIND_DEBUG_MODE FALSE )

# Create a target to build an executable
add_executable(fetch_content_example)
# set the c++ version required

target_compile_features(
    fetch_content_example
    PRIVATE cxx_std_11
)
# Add source files to 'hello_world' target
target_sources(
    fetch_content_example
    PRIVATE src/main.cpp
)

# link the openssl library to the executable
target_link_libraries(
    fetch_content_example
    PRIVATE bertrand::bertrand
)
