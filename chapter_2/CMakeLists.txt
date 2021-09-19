# ______________________________________________________
# Top-level CMakeLists file for the Chapter 2 example content.
#
# @file     CMakeLists.txt
# @author   Mustafa Kemal GILOR <mustafagilor@gmail.com>
# @date     19.09.2021
# 
# SPDX-License-Identifier: MIT
# ______________________________________________________

cmake_minimum_required(VERSION 3.21)

project(
  "CMake Tips and Tricks Chapter 2"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

# Set C++ standard to 11 for all subdirectories (component1, component2, driver_app)
# in this folder.
set(CMAKE_CXX_STANDARD 11)
# Make C++ 11 standard a must. Setting CMAKE_CXX_STANDARD is a *should* by default. 
# When this variable is set and selected compiler does not support C++11, the CMake 
# configure step will fail.
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(component_interface)
add_subdirectory(component1)
add_subdirectory(component2)
add_subdirectory(driver_app)