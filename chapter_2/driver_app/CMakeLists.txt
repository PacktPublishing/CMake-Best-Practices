# ______________________________________________________
# CMakeLists file for the Chapter 2 - Driver Application
#
# @file     CMakeLists.txt
# @author   Mustafa Kemal GILOR <mustafagilor@gmail.com>
# @date     19.09.2021
# 
# SPDX-License-Identifier: MIT
# ______________________________________________________

add_executable(driver_application)
target_sources(driver_application PRIVATE src/main.cpp)
target_link_libraries(driver_application PUBLIC framework.component1 framework.component2)