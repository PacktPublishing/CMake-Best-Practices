# ______________________________________________________
# CMakeLists file for the Chapter 2 - Component 1
#
# @file     CMakeLists.txt
# @author   Mustafa Kemal GILOR <mustafagilor@gmail.com>
# @date     19.09.2021
# 
# SPDX-License-Identifier: MIT
# ______________________________________________________

add_library(framework.component1 STATIC)
target_include_directories(framework.component1 PUBLIC include/)
target_sources(framework.component1 PRIVATE src/component1.cpp)
target_link_libraries(framework.component1 PUBLIC framework.component_interface)
