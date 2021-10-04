# Chapter3-  creating a binary library
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.17)

project(
  hello
  VERSION 1.0.0
  DESCRIPTION
    "A simple C++ project to demonstrate creating executables and libraries in CMake"
  LANGUAGES CXX)

# set the postfix "d" for the resulting .so or .dll files when building the
# library in debug mode

set(CMAKE_DEBUG_POSTFIX d)

# Since windows by default hides all symbols in DLLs, this behavior is changed
# here
if(MSVC)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
  set(BUILD_SHARED_LIBS TRUE)
endif()

# add the library target
add_library(hello SHARED)

# set properties for the target. * DEBUG_POSTFIX append a "d" to the library
# name when building in debug mode * VERSION set the library version to the
# project version * SOVERSION set the compatibility  version for the library to
# the major number of the version
set_target_properties(
  hello
  PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
             VERSION ${PROJECT_VERSION}
             SOVERSION ${PROJECT_VERSION_MAJOR})

# add sources to the library target
target_sources(
  hello
  PRIVATE src/hello.cpp src/internal.cpp
  PUBLIC include/hello/hello.hpp)

# define the C++ standard needed to compile this library and make it visible to
# dependers
target_compile_features(hello PUBLIC cxx_std_17)

# set the include directories
target_include_directories(
  hello
  PRIVATE src/hello
  PUBLIC include)
