# CMakeLists creating a simple executable that links to a library found in the default search path
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    ch5_find_package_example
    VERSION 1.0
    DESCRIPTION
        "A simple C++ project to demonstrate creating a standalone executables"
    LANGUAGES CXX
)

# enable debuging for finding the package (For illustrative purposes)
# set(CMAKE_FIND_DEBUG_MODE TRUE )
find_package(OpenSSL REQUIRED COMPONENTS SSL)
# # disable debugging again set(CMAKE_FIND_DEBUG_MODE FALSE )

# Create a target to build an executable
add_executable(ch5_find_package_example)
# set the c++ version required

target_compile_features(
    ch5_find_package_example
    PRIVATE cxx_std_11
)
# Add source files to 'hello_world' target
target_sources(
    ch5_find_package_example
    PRIVATE src/main.cpp
)

# link the openssl library to the executable
target_link_libraries(
    ch5_find_package_example
    PRIVATE OpenSSL::SSL
)
