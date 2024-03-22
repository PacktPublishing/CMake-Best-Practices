# - Environment file utility module implementation
#
# This module provides the function read_environment_file()
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

include_guard(DIRECTORY)

# Read an environment file and declare each environment
# variable defined in it with set(...) cmake function.
# Used with permission from hadouken project: https://github.com/mustafakemalgilor/hadouken/blob/master/hadouken.cmake
function(read_environment_file ENVIRONMENT_FILE_NAME)

    file(STRINGS ${ENVIRONMENT_FILE_NAME} KVP_LIST ENCODING UTF-8)

    foreach(ENV_VAR_DECL IN LISTS KVP_LIST)
        # Trim begin and end
        string(STRIP ENV_VAR_DECL ${ENV_VAR_DECL})

        # Skip empty lines
        string(LENGTH ENV_VAR_DECL ENV_VAR_DECL_LEN)
        if(ENV_VAR_DECL_LEN EQUAL 0)
            continue()
        endif()

        # Skip comments
        string(SUBSTRING ${ENV_VAR_DECL} 0 1 ENV_VAR_DECL_FC)

        if(ENV_VAR_DECL_FC STREQUAL "#")
            continue()
        endif()

        # Convert environment variable declaration to cmake list
        string(REPLACE "=" ";" ENV_VAR_SPLIT ${ENV_VAR_DECL})

        list(GET ENV_VAR_SPLIT 0 ENV_VAR_NAME)
        list(GET ENV_VAR_SPLIT 1 ENV_VAR_VALUE)

        # Replace quotes in environment variable values
        string(REPLACE "\"" "" ENV_VAR_VALUE ${ENV_VAR_VALUE})

        set(${ENV_VAR_NAME} ${ENV_VAR_VALUE} PARENT_SCOPE)
    endforeach()
endfunction()