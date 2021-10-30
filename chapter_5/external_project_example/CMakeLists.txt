# Illustrating the use of ExternalProject
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    external_project_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate fetching external content"
    LANGUAGES CXX
)
include(ExternalProject)

ExternalProject_Add(
  bertrand_downloaded
  URL https://github.com/bernedom/bertrand/archive/refs/tags/0.0.17.tar.gz
  INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/bertrand_downloaded_install
  CMAKE_ARGS -D BERTRAND_BUILD_TESTING=OFF             
             -D CMAKE_INSTALL_PREFIX=<INSTALL_DIR>
)

# Create a target to build an executable
add_executable(external_project_example)
# set the c++ version required

target_compile_features(
    external_project_example
    PRIVATE cxx_std_11
)
# Add source files to 'hello_world' target
target_sources(
    external_project_example
    PRIVATE src/main.cpp
)
# make the executable to be built depend on the external project
# to force downloading first
add_dependencies(external_project_example bertrand_downloaded)

# make the header file for bertrand available
target_include_directories(external_project_example PRIVATE 
                          ${CMAKE_CURRENT_BINARY_DIR}/bertrand_downloaded_install/include
)
