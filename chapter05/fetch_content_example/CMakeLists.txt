# Chapter 5 - Example to illustrate the use of FetchContent
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    ch5_fetch_content_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate fetching external content"
    LANGUAGES CXX
)
# make the FetchContent module available
include(FetchContent)

# declare where to get si from 
FetchContent_Declare(
  SI
  GIT_REPOSITORY https://github.com/bernedom/si.git
  GIT_TAG 5f4b9a5924a8b3509baec07525fda9ad926adcec) # 2.3.0

# populate si to make it available
FetchContent_MakeAvailable(si)

# Create a target to build an executable
add_executable(ch5_fetch_content_example)
# set the c++ version required

target_compile_features(
    ch5_fetch_content_example
    PRIVATE cxx_std_17
)
# Add source files to 'ch5_fetch_content_example' target
target_sources(
    ch5_fetch_content_example
    PRIVATE src/main.cpp
)

# link the si library to the executable
target_link_libraries(
    ch5_fetch_content_example
    PRIVATE SI::SI
)
