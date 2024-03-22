# - Git utility module implementation
#
# This module provides the macros git_get_branch_name(), git_get_head_commit_hash(), git_get_config_value().
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

include_guard(DIRECTORY)

find_package(Git REQUIRED QUIET)

macro(git_get_branch_name result_var_name)
    execute_process(
        COMMAND "${GIT_EXECUTABLE}" symbolic-ref -q --short HEAD
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        OUTPUT_VARIABLE ${result_var_name}
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
endmacro()

macro (git_get_head_commit_hash result_var_name)
    execute_process(
        COMMAND "${GIT_EXECUTABLE}" rev-parse --verify HEAD
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        OUTPUT_VARIABLE ${result_var_name}
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
endmacro()

macro (git_get_config_value config_key result_var_name)
    execute_process(
        COMMAND "${GIT_EXECUTABLE}" config --get ${config_key}
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        OUTPUT_VARIABLE ${result_var_name}
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
endmacro()
