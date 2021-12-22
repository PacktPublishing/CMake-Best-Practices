# CMakeLists creating a simple executable that links to a system library
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    find_package_example
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
add_executable(find_package_example)
# set the c++ version required

target_compile_features(
    find_package_example
    PRIVATE cxx_std_11
)
# Add source files to 'hello_world' target
target_sources(
    find_package_example
    PRIVATE src/main.cpp
)

# link the openssl library to the executable
target_link_libraries(
    find_package_example
    PRIVATE OpenSSL::SSL
)
