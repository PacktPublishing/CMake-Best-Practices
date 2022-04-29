# Chapter 5 - Example illustrating how to create a simple executable that links library retrieved with conan
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

# using language CXX and C is necessary so conan recognizes the compiler correctly when compiling with clang under windows
project(
    ch5_conan_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate fetching conan packages directly out of CMake"
    LANGUAGES CXX C
)

# Download conan.cmake if it does not already exist
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file( DOWNLOAD
  "https://raw.githubusercontent.com/conan-io/cmake-conan/0.17.0/conan.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake"
    EXPECTED_HASH
    SHA256=3bef79da16c2e031dc429e1dac87a08b9226418b300ce004cc125a82687baeef
    STATUS download_status
    )

  if(NOT download_status MATCHES "^0;")
    message(FATAL_ERROR "Downloading conan.cmake failed with ${download_status}")
  endif()
endif()
# include the downloaded conan module to use its functionality
include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)

# retrieve the current CMake settings and store them in CONAN_SETTINGS
conan_cmake_autodetect(CONAN_SETTINGS)

# Pass the dependencies to conan
conan_cmake_configure(REQUIRES fmt/6.1.2 GENERATORS cmake_find_package_multi)

# install all the configured dependencies locally
conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    SETTINGS ${CONAN_SETTINGS}
                  )

# Append the current binary dir to CMAKE_PREFIX_PATH so the conan package are found
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

# use the just downloaded package 
find_package(fmt 6.1 REQUIRED)

# Create a target to build an executable
add_executable(ch5_conan_example)
# set the c++ version required

target_compile_features(
    ch5_conan_example
    PRIVATE cxx_std_11
)
# Add source files to 'hello_world' target
target_sources(
    ch5_conan_example
    PRIVATE src/main.cpp
)

# link the fmt library to the executable
target_link_libraries(
    ch5_conan_example
    PRIVATE fmt::fmt
)
