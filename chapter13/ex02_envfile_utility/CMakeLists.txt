# CMakeLists file for the Chapter 13 Example nr. 01: 
# Git utility module
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  ch13_ex01_git_module
  VERSION 1.0
  DESCRIPTION "Chapter 13 Example 01, git utility module example"
  LANGUAGES CXX)

# Add cmake folder to the module path, so subsequent include() calls
# can directly include modules under cmake/ folder by specifying the name only.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/)

add_subdirectory(test-executable)