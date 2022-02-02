
# CMakeLists file for the Chapter 1 example
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch12_check_compiler_feature
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

include(CheckSourceCompiles)

check_source_compiles(CXX "
#include <atomic>
int main(){
  std::atomic<unsigned int> x;
  x.fetch_add(1);
  x.fetch_sub(1);
}" HAS_STD_ATOMIC)

if(HAS_STD_ATOMIC)
  message(STATUS "std::atomic supported")
else()
  message(STATUS "std::atomic NOT supported")
endif()

