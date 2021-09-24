cmake_minimum_required(VERSION 3.17)

project(
  ch3.hello_lib
  VERSION 1.0
  DESCRIPTION
    "A simple C++ project to demonstrate creating executables and libraries in CMake"
  LANGUAGES CXX)

add_library(hello SHARED)

target_sources(
  hello
  PRIVATE src/hello.cpp src/internal.cpp
  PUBLIC include/hello/hello.hpp)

target_include_directories(
  hello
  PRIVATE src/hello
  PUBLIC include)
