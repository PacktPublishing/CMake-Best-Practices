# Illustrating the use of FetchContent
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    fetch_content_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate fetching external content"
    LANGUAGES CXX
)
# make the FetchContent module available
include(FetchContent)

# declare where to get bertrand from 
FetchContent_Declare(
  bertrand
  GIT_REPOSITORY https://github.com/bernedom/bertrand.git
  GIT_TAG f88bf21b3a651c07e94a9a9c33607dd659fe6318) # 0.0.17

# populate bertrand to make it available
FetchContent_MakeAvailable(bertrand)

# Create a target to build an executable
add_executable(fetch_content_example)
# set the c++ version required

target_compile_features(
    fetch_content_example
    PRIVATE cxx_std_11
)
# Add source files to 'fetch_content_example' target
target_sources(
    fetch_content_example
    PRIVATE src/main.cpp
)

# link the bertrand library to the executable
target_link_libraries(
    fetch_content_example
    PRIVATE bertrand::bertrand
)
