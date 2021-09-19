# ______________________________________________________
# CMakeLists file for the Chapter 2 - Component 2
#
# @file     CMakeLists.txt
# @author   Mustafa Kemal GILOR <mustafagilor@gmail.com>
# @date     19.09.2021
# 
# SPDX-License-Identifier: MIT
# ______________________________________________________

add_library(framework.component2 SHARED)
target_include_directories(framework.component2 PUBLIC include/)
target_sources(framework.component2 PRIVATE src/component2.cpp)
target_link_libraries(framework.component2 PUBLIC framework.component_interface)