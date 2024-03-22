# CMakeLists file for the Chapter 4 Example nr. 6: 
# CPack example
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  ch4_ex06_executable
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 06, CPack example"
  LANGUAGES CXX)

# Define the executable that will consume the ch4_ex05_lib package
add_executable(ch4_ex06_executable src/main.cpp)

# Set the required C++ standard for the target
target_compile_features(ch4_ex06_executable PRIVATE cxx_std_11)

# Link executable target to library target
target_link_libraries(ch4_ex06_executable PRIVATE ch4_ex06_library)

install(TARGETS ch4_ex06_executable)