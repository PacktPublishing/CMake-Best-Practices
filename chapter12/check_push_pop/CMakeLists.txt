# Chapter 12 example to illustrate saving results for compiler checks
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    ch12_check_push_pop
    VERSION 1.0
    DESCRIPTION
        "Example to show cmake_push_check_state and cmake_pop_check_state"
    LANGUAGES CXX
)

# Start with a known state, so we can modify and undo later
include(CMakePushCheckState)
cmake_push_check_state()

# clean all variables required for check state
cmake_reset_check_state()

# use a checkmodule to check if the current C++ compiler supports the -Wall flag
include(CheckCompilerFlag)
check_compiler_flag(CXX -Wall WALL_FLAG_SUPPORTED)

# if the flag is set, set it as a required flag
if(WALL_FLAG_SUPPORTED)
    set(CMAKE_REQUIRED_FLAGS -Wall)

    # Preserve -Wall and add more things for extra checks
    cmake_push_check_state()
        # set the current include dir as required
        set(CMAKE_REQUIRED_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)

        # use the checkSymbolExists module to check if the symbol `hello` exists 
        # in the hello.hpp 
        include(CheckSymbolExists)
        check_symbol_exists(hello "hello.hpp" HAVE_HELLO_SYMBOL)

    # reset the check state 
    cmake_pop_check_state()

endif()
cmake_pop_check_state() ## restore all CMAKE_REQUIRED_VARIABLEs to original state

