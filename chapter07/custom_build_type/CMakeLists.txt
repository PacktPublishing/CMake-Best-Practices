# CMakeLists file for the Chapter 7. Example to show how to create a custom build type for a coverage build
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    "ch7_custom_build_type"
    VERSION 1.0
    DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
    LANGUAGES CXX)
#include CTest module for defining tests later
include(CTest)

# Check if the currenct generator is a multi-configuration generator or not
get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

# For multi-config generators add the build configuration "Coverage" to the 
# list of available build configs
if(isMultiConfig)
    if(NOT "Coverage" IN_LIST CMAKE_CONFIGURATION_TYPES)
        list(APPEND CMAKE_CONFIGURATION_TYPES Coverage)
    endif()
else()
    # If a single configuration set describe the cache variable CMAKE_BUILD_TYPE with the allowed
    # values for build types
    set(allowedBuildTypes Debug Release Coverage RelWithDebugInfo MinSizeRel)
    set_property(
        CACHE CMAKE_BUILD_TYPE
        PROPERTY STRINGS "${allowedBuildTypes}"
    )
    # if the build type is not set force it to debug
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
    # If the build type is unknown fail configuration witn an error
    elseif(NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
        message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
    endif()
endif()

# Set various flags for the compiler to enable building coverage
# The Coverage build type is based on the debug build type and usess
# any flags set in the debug type
set(CMAKE_C_FLAGS_COVERAGE "${CMAKE_C_FLAGS_DEBUG} --coverage" CACHE STRING "") 
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG} --coverage" CACHE STRING "")
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --coverage" CACHE STRING "")
set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} --coverage" CACHE STRING "")
set(CMAKE_STATIC_LINKGER_FLAGS_COVERAGE "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} --coverage" CACHE STRING "")
set(CMAKE_MODULE_LINKER_FLAGS_COVERAGE "${CMAKE_MODULE_LINKER_FLAGS_DEBUG} --coverage" CACHE STRING "")

# Mark the flags for the Coverage build type advanced to prevent accidential tampering 
# with the flags
mark_as_advanced(CMAKE_C_FLAGS_COVERAGE 
                 CMAKE_CXX_FLAGS_COVERAGE 
                 CMAKE_EXE_LINKER_FLAGS_COVERAGE 
                 CMAKE_SHARED_LINKER_FLAGS_COVERAGE 
                 CMAKE_STATIC_LINKGER_FLAGS_COVERAGE 
                 CMAKE_MODULE_LINKER_FLAGS_COVERAGE)


# Mark the Coverage build type as a debug configuration
set_property(GLOBAL APPEND PROPERTY DEBUG_CONFIGURATIONS Coverage)

# Add an example library and executable to illustrate the coverage report
add_library(ch7_custom_build_type STATIC)
target_include_directories(ch7_custom_build_type PUBLIC include)
target_compile_features(ch7_custom_build_type PUBLIC cxx_std_11)
target_sources(ch7_custom_build_type PRIVATE src/coverage_example/coverage_example.cpp)


add_executable(ch7_custom_build_type_test src/coverage_test.cpp)
target_link_libraries(ch7_custom_build_type_test ch7_custom_build_type)

target_compile_features(ch7_custom_build_type_test PRIVATE cxx_std_11)
add_test(NAME code_coverage_test COMMAND ch7_custom_build_type_test)