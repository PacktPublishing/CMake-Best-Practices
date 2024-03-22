# Top-level CMakeLists file for the Chapter 8 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  "CMake Best Practices Chapter 8"
  VERSION 1.0
  DESCRIPTION
    "A collection of sample C++ applications and libraries to demonstrate usage of custom commands and custom targets"
  LANGUAGES CXX)

add_subdirectory(custom_target_example)
add_subdirectory(custom_command_example)
add_subdirectory(create_source_file_example)
add_subdirectory(chaining_custom_commands_example)
add_subdirectory(custom_target_dependency_example)
add_subdirectory(execute_process_example)
add_subdirectory(configure_file_example)
