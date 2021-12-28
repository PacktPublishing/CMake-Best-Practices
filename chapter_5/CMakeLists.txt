# Top-level CMakeLists file for the Chapter 5 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    "Chapter_5"
    VERSION 1.0
    DESCRIPTION
        "A collection of sample C++ projects to demonstrate using external dependencies"
    LANGUAGES CXX
)

add_subdirectory(find_package_example)
add_subdirectory(find_module)
add_subdirectory(fetch_content_example)
add_subdirectory(external_project_example)

find_program(CONAN_EXECUTABLE conan)

if(CONAN_EXECUTABLE)
    add_subdirectory(conan_example)
    add_subdirectory(conan_conanfile_example)
else()
    message(STATUS "Conan not found. Will not build conan examples")
endif()


find_program(VCPKG_EXECUTABLE vcpkg)

# if vcpkg not found or toolchain file does not match vcpkg.cmake exclude the vcpkg example 
if(NOT VCPKG_EXECUTABLE OR NOT CMAKE_TOOLCHAIN_FILE MATCHES "vcpkg.cmake$")
  message(STATUS "vcpkg not found or vcpkg toolchain not set. Will not build vcpkg example")
else()
    add_subdirectory(vcpkg_example)
endif()