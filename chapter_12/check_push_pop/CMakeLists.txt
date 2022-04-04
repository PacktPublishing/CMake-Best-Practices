# CMakeLists file for the Chapter 12 example
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    ch12_check_push_pop
    VERSION 1.0
    DESCRIPTION
        "Example to show cmake_push_check_state and cmake_pop_check_state"
    LANGUAGES CXX
)

# Start with a known state we can modify and undo later
include(CMakePushCheckState)
cmake_push_check_state()

# clean all variables required for check state
cmake_reset_check_state()

include(CheckCompilerFlag)
check_compiler_flag(CXX -Wall WALL_FLAG_SUPPORTED)

if(WALL_FLAG_SUPPORTED)
    set(CMAKE_REQUIRED_FLAGS -Wall)

    # Preserve -Wall and add more things for extra checks
    cmake_push_check_state()
        set(CMAKE_REQUIRED_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)
        include(CheckSymbolExists)
        
        check_symbol_exists(hello "hello.hpp" HAVE_HELLO_SYMBOL)

    cmake_pop_check_state()

endif()
cmake_pop_check_state() ## restore all CMAKE_REQUIRED_VARIABLEs to original state

