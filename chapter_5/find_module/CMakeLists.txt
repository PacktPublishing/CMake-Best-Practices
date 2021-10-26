# CMakeLists to show how find-modules work
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

# the following code is used to set up the example for the find_module calling cmake
# from itself is dangerous and should not be done in practice
# this will configure and build the hello_lib from chapter3 into the folder ./dep
# it will not perform a regular installation as the idea is to provide an example of how to find non-cmake projects

execute_process(
    COMMAND cmake -S ${CMAKE_CURRENT_SOURCE_DIR}/../../chapter_3/hello_lib/ -B ${CMAKE_CURRENT_SOURCE_DIR}/dep/build/ -DCMAKE_LIBRARY_OUTPUT_DIRECTORY=${CMAKE_CURRENT_SOURCE_DIR}/dep/lib/
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

execute_process(
    COMMAND cmake --build ${CMAKE_CURRENT_SOURCE_DIR}/dep/build/
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

execute_process(
    COMMAND cmake -E copy_directory ../../chapter_3/hello_lib/include ${CMAKE_CURRENT_SOURCE_DIR}/dep/include 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Create a target to build an executable
add_executable(find_module_example)
# set the c++ version required

target_compile_features(
    find_module_example
    PRIVATE cxx_std_11
)
# Add source files to 'hello_world' target
target_sources(
    find_module_example
    PRIVATE src/main.cpp
)
