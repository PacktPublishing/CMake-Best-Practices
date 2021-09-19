# ______________________________________________________
# CMakeLists file for the Chapter 2 - Component 2
#
# @file     CMakeLists.txt
# @author   Mustafa Kemal GILOR <mustafagilor@gmail.com>
# @date     19.09.2021
# 
# SPDX-License-Identifier: MIT
# ______________________________________________________

project(
    ch2.framework.component2
    VERSION 1.0
    DESCRIPTION "Chapter 2 component 2 implementation"
    LANGUAGES CXX
)

add_library(${PROJECT_NAME} SHARED) # Create a shared library target named ch2.framework.component2 (retrieved from project name variable) 
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/) # Add include/ to include directories with visibility of PUBLIC.  
target_sources(${PROJECT_NAME} PRIVATE src/component2.cpp) # Add src/component2.cpp file as sources to the target with PRIVATE visibility.
target_link_libraries(${PROJECT_NAME} PUBLIC ch2.framework.component_interface) # Link against ch2.framework.component_interface