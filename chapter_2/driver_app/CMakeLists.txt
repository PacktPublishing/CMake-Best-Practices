# ______________________________________________________
# CMakeLists file for the Chapter 2 - Driver Application
#
# @file     CMakeLists.txt
# @author   Mustafa Kemal GILOR <mustafagilor@gmail.com>
# @date     19.09.2021
# 
# SPDX-License-Identifier: MIT
# ______________________________________________________

# Project directive is used for creating a child project for the targets we're going to create
# for the component. This will allow us to use project() variables in target creation. 
project(
    ch2.driver_application
    VERSION 1.0
    DESCRIPTION "Chapter 2 driver application implementation"
    LANGUAGES CXX
)

add_executable(${PROJECT_NAME}) # Create an executable target named with the same name as project name (ch2.driver_application)
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp) # Add src/main.cpp as source to the target
target_link_libraries(${PROJECT_NAME} PRIVATE ch2.framework.component1 ch2.framework.component2) # Link target against ch2.framework.component1 and ch2.framework.component2