# CMakeLists creating a simple executable that links to a system library
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    conan_conanfile_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating a standalone executables"
    LANGUAGES CXX
)
find_program(CONAN conan)




# if built within conan use the file from local cache
if(CONAN)
  # setting up conan to download.cmake automatically
  if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/bernedom/cmake-conan")
    file( DOWNLOAD
      "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
      "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
  endif()
  include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)

  conan_cmake_autodetect(CONAN_SETTINGS)
  
  conan_cmake_run(CONANFILE ${CMAKE_CURRENT_LIST_DIR}/conanfile.txt 
                  BASIC_SETUP
                  BUILD missing
                  SETTINGS ${CONAN_SETTINGS})
                  
else()
  message(WARNING "Conan not found. Will not build conan example")
  return()
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})

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

# link the openssl library to the executable
target_link_libraries(
    conan_conanfile_example
    PRIVATE fmt::fmt
)
