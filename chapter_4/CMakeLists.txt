# Top-level CMakeLists file for the Chapter 4 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "CMake Best Practices Chapter 4"
  VERSION 1.0
  DESCRIPTION
    "A collection of sample C++ applications and libraries to demonstrate installing and packaging project artifacts"
  LANGUAGES CXX)

add_subdirectory(ex01_executable)
add_subdirectory(ex02_static)
add_subdirectory(ex03_file)
add_subdirectory(ex04_directory)
add_subdirectory(ex05_config_file_package)
# ex05_consumer & ex06_pack are intentionally left out of the project
# since they are intended be standalone projects independent from the
# root project. 
