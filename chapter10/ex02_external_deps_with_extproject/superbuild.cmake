# Super-build code for Chapter 10, example 02.
#
# SPDX-License-Identifier: MIT

# We will utilize the ExternalProject module for satisfying the catch2 dependency.
include(ExternalProject)

# Declare catch2 dependency details. We will explicitly require 2.13.9 version this time.
ExternalProject_Add(catch2_download
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.9
    INSTALL_COMMAND ""
    # For disabling the warning that treated as an error
    CMAKE_ARGS -DCMAKE_CXX_FLAGS="-Wno-error=pragmas"
)

# The catch2 headers will be present in this directory after download.
SET(CATCH2_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/catch2_download-prefix/src/catch2_download/single_include)

# Since the include directory of the catch2 is not available at the configure stage 
# (ExternalProject_Add retrieves and builds the dependency at build stage)
# we'll just go ahead and create the include directory, so we can list that directory in
# INTERFACE_INCLUDE_DIRECTORIES property of the catch2 target.
file(MAKE_DIRECTORY ${CATCH2_INCLUDE_DIR})

# Define an imported library for the catch2
add_library(catch2 IMPORTED INTERFACE)
# Make the library dependent on the ExternalProject target, so CMake knows that in order
# to use this target, the ExternalProject target must be built first
add_dependencies(catch2 catch2_download)
# Add CATCH2_INCLUDE_DIR to INTERFACE_INCLUDE_DIRECTORIES of the catch2 target, so the libraries
# depending on catch2 will automatically be able to include catch2 headers.
set_target_properties(catch2 PROPERTIES "INTERFACE_INCLUDE_DIRECTORIES" "${CATCH2_INCLUDE_DIR}")