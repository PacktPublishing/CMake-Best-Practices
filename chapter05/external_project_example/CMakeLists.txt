# Chapter 5 - Example Illustrating the use of ExternalProject
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    ch5_external_project_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate fetching external content"
    LANGUAGES CXX
)
# include the module `ExternalProject`
include(ExternalProject)

# Add an external project from a downloaded source archive
ExternalProject_Add(
  bertrand
  URL https://github.com/bernedom/bertrand/archive/refs/tags/0.0.17.tar.gz
  URL_HASH MD5=354141c50b8707f2574b69f30cef0238
  
  INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/bertrand_install
  CMAKE_CACHE_ARGS -DBERTRAND_BUILD_TESTING:BOOL=OFF      
                   -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)
# Retrieve the installation directory of bertrand
ExternalProject_Get_Property(bertrand INSTALL_DIR)
# Populate the installation directory to the variable BERTRAND_INSTALL_DIR
set(BERTRAND_INSTALL_DIR "${INSTALL_DIR}")

# Add an extra step after the build step to extract and archive the license file
ExternalProject_Add_Step(bertrand copy_license 
                        COMMAND ${CMAKE_COMMAND} -E tar "cvzf" 
                                ${CMAKE_CURRENT_BINARY_DIR}/licenses.tar.gz <SOURCE_DIR>/LICENSE 
                        DEPENDEES build
                        ALWAYS YES
)

# Create a target to build an executable
add_executable(ch5_external_project_example)
# set the c++ version required

target_compile_features(
    ch5_external_project_example
    PRIVATE cxx_std_17
)
# Add source files to 'ch5_external_project_example' target
target_sources(
    ch5_external_project_example
    PRIVATE src/main.cpp
)
# make the executable to be built depend on the external project
# to force downloading first
add_dependencies(ch5_external_project_example bertrand)

# make the header file for bertrand available
target_include_directories(ch5_external_project_example PRIVATE 
                          ${BERTRAND_INSTALL_DIR}/include
)
