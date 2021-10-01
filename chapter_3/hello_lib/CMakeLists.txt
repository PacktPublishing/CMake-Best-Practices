cmake_minimum_required(VERSION 3.17)

project(
  ch3.hello_lib
  VERSION 1.0.0
  DESCRIPTION
    "A simple C++ project to demonstrate creating executables and libraries in CMake"
  LANGUAGES CXX)

set(CMAKE_DEBUG_POSTFIX d)

if(MSVC)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
  set(BUILD_SHARED_LIBS TRUE)
endif()

add_library(hello SHARED)

set_target_properties(
  hello
  PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
             VERSION ${PROJECT_VERSION}
             SOVERSION ${PROJECT_VERSION_MAJOR})

target_sources(
  hello
  PRIVATE src/hello.cpp src/internal.cpp
  PUBLIC include/hello/hello.hpp)

target_compile_features(hello PUBLIC cxx_std_17)

target_include_directories(
  hello
  PRIVATE src/hello
  PUBLIC include)
