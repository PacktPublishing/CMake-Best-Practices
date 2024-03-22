# Chapter 5 - Example illustrating how to use conan with a conanfile.txt
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    conan_conanfile_example
    VERSION 1.0
    DESCRIPTION
        "AC++ project to demonstrate using a conanfile.txt from within CMake"
    LANGUAGES CXX
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
# Detect the current settings of cmake and store them for conan in CONAN_SETTINGS
conan_cmake_autodetect(CONAN_SETTINGS)

# Run conan to set up the dependencies
conan_cmake_run(CONANFILE ${CMAKE_CURRENT_LIST_DIR}/conanfile.txt 
                BASIC_SETUP
                BUILD missing
                SETTINGS ${CONAN_SETTINGS})
                

# Append the current binary dir to CMAKE_PREFIX_PATH so the conan package are found
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

# find the just downloaded package
find_package(fmt 6.1 REQUIRED)

# Create a target to build an executable
add_executable(conan_conanfile_example)
# set the c++ version required

target_compile_features(
    conan_conanfile_example
    PRIVATE cxx_std_11
)
# Add source files to 'hello_world' target
target_sources(
    conan_conanfile_example
    PRIVATE src/main.cpp
)

# link the fmt library to the executable
target_link_libraries(
    conan_conanfile_example
    PRIVATE fmt::fmt
)
