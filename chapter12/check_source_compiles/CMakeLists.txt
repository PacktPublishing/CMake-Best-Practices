
# CMakeLists file for the Chapter 12 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch12_check_compiler_feature
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

# include the module to check if the source compiles
include(CheckSourceCompiles)

# check if the soure compiles and save the result in HAS_STD_ATOMIC
check_source_compiles(CXX "
#include <atomic>
int main(){
  std::atomic<unsigned int> x;
  x.fetch_add(1);
  x.fetch_sub(1);
}" HAS_STD_ATOMIC)

# Print a status message depending on the result of the compile check
if(HAS_STD_ATOMIC)
  message(STATUS "std::atomic supported")
else()
  message(STATUS "std::atomic NOT supported")
endif()

