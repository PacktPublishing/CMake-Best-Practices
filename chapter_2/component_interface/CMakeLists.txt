# ______________________________________________________
# CMakeLists file for the Chapter 2 - Component Interface
#
# @file     CMakeLists.txt
# @author   Mustafa Kemal GILOR <mustafagilor@gmail.com>
# @date     19.09.2021
# 
# SPDX-License-Identifier: MIT
# ______________________________________________________

project(
    ch2.framework.component_interface
    VERSION 1.0
    DESCRIPTION "Chapter 2 component interface implementation"
    LANGUAGES CXX
)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include/)