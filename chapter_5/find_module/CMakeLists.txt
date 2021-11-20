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

# the following code is used to set up and build the library which we want to find with the find_module.
# calling cmake from itself is dangerous and should not be done in practice
# this will configure and build the hello_lib from chapter3 into the folder ./dep
# it will not perform a regular installation as the idea is to provide an example of how include binary projects 
# by using a custom written find_module

execute_process(
    COMMAND cmake -S ${CMAKE_CURRENT_SOURCE_DIR}/dep_source/ -B ${CMAKE_CURRENT_SOURCE_DIR}/dep/build/ -DCMAKE_LIBRARY_OUTPUT_DIRECTORY=${CMAKE_CURRENT_SOURCE_DIR}/dep/lib/ -DCMAKE_BUILD_TYPE=Release -G${CMAKE_GENERATOR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

execute_process(
    COMMAND cmake --build ${CMAKE_CURRENT_SOURCE_DIR}/dep/build/ --config Release
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

execute_process(
    COMMAND cmake -E copy_directory dep_source/include ${CMAKE_CURRENT_SOURCE_DIR}/dep/include 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
# End of setting up block - The example starts below

# Tell CMake where to look for find modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# try to find the package obscure see the file cmake/FindObscure.cmake for the innner workings
find_package(Obscure REQUIRED)

# Create a target to build an executable
add_executable(find_module_example)
target_link_libraries(find_module_example Obscure::Obscure)
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
