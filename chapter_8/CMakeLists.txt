# Top-level CMakeLists file for the Chapter 6 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "CMake Best Practices Chapter 8"
  VERSION 1.0
  DESCRIPTION
    "A collection of sample C++ applications and libraries to demonstrate usage of custom commands and custom targets"
  LANGUAGES CXX)

add_subdirectory(custom_target_example)
add_subdirectory(clang-format-example)
add_subdirectory(create_hash_example)
add_subdirectory(hash_target_example)