# CMakeLists creating a simple executable that links library retrieved with conan
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    ch5_conan_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating a standalone executables"
    LANGUAGES CXX
)
find_program(CONAN conan)

# if built within conan use the file from local cache
if(CONAN)
  
  if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file( DOWNLOAD
      "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
      "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
  endif()
  include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)
  
  # Pass the dependencies to conan
  conan_cmake_configure(REQUIRES fmt/6.1.2 GENERATORS cmake_find_package)

  # retrieve the current CMake settings and store them in CONAN_SETTINGS
  conan_cmake_autodetect(CONAN_SETTINGS)
  
  # install all the configured dependencies locally
  conan_cmake_install(PATH_OR_REFERENCE ${CMAKE_CURRENT_LIST_DIR}
                      BUILD missing
                      REMOTE conancenter
                      SETTINGS ${CONAN_SETTINGS}
                    )
else()
  message(WARNING "Conan not found. Will not build conan example")
  return()
endif()

# Append the current binary dir to CMAKE_MODULE_PATH because conan stores the configuration for the dependencies there
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})

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
