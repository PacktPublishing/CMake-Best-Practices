# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    "ch7_custom_build_type"
    VERSION 1.0
    DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
    LANGUAGES CXX)

include(CTest)
get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(isMultiConfig)
    if(NOT "Coverage" IN_LIST CMAKE_CONFIGURATION_TYPES)
        list(APPEND CMAKE_CONFIGURATION_TYPES Coverage)
    endif()
else()
    set(allowedBuildTypes Debug Release Coverage)
    set_property(
        CACHE CMAKE_BUILD_TYPE
        PROPERTY STRINGS "${allowedBuildTypes}"
    )
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
    elseif(NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
        message(FATAL_ERROR "Unknown build type: ${CMAKE_BUILD_TYPE}")
    endif()
endif()

set(CMAKE_C_FLAGS_COVERAGE "${CMAKE_C_FLAGS_DEBUG} --coverage" CACHE STRING "") 
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG} --coverage" CACHE STRING "")
set(CAMKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --coverage" CACHE STRING "")
set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} --coverage" CACHE STRING "")
set(CMAKE_STATIC_LINKGER_FLAGS_COVERAGE "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} --coverage" CACHE STRING "")
set(CMAKE_MODULE_LINKER_FLAGS_COVERAGE "${CMAKE_MODULE_LINKER_FLAGS_DEBUG} --coverage" CACHE STRING "")

add_library(ch7_custom_build_type STATIC)
target_include_directories(ch7_custom_build_type PUBLIC include)
target_compile_features(ch7_custom_build_type PUBLIC cxx_std_11)
target_sources(ch7_custom_build_type PRIVATE src/coverage_example/coverage_example.cpp)


add_executable(ch7_custom_build_type_test src/coverage_test.cpp)
target_link_libraries(ch7_custom_build_type_test ch7_custom_build_type)

target_compile_features(ch7_custom_build_type_test PRIVATE cxx_std_11)
add_test(NAME code_coverage_test COMMAND ch7_custom_build_type_test)