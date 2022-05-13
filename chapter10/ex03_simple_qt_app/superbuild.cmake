# Super-build code for Chapter 10, example 03.
#
# SPDX-License-Identifier: MIT

# We will utilize the FetchContent module for satisfying the google benchmark and google test dependencies.
include(FetchContent)

message(STATUS "Chapter 10, example 03 superbuild enabled. Will try to satisfy dependencies for the example.")

set(FETCHCONTENT_QUIET FALSE) # Enable message output for FetchContent commands

# May require installing libgl1-mesa-dev libglu1-mesa-dev '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev libxkbcommon-dev libxkbcommon-x11-dev packages.
# (or equivalent)

# Only build the following QT submodules:
set(QT_BUILD_SUBMODULES "qtbase" CACHE STRING "Submodules to build")
set(QT_WILL_BUILD_TOOLS on)

# Disable some unnecessary QT features to reduce the build time.
set(QT_FEATURE_sql off)
set(QT_FEATURE_network off)
set(QT_FEATURE_dbus off)
set(QT_FEATURE_opengl off)
set(QT_FEATURE_testlib off)
set(QT_BUILD_STANDALONE_TESTS off)
set(QT_BUILD_EXAMPLES off)
set(QT_BUILD_TESTS off)

# Declare QT6 dependency details. We will explicitly require 6.3.0 version this time.
FetchContent_Declare(qt6
    GIT_REPOSITORY https://github.com/qt/qt5.git
    GIT_TAG        v6.3.0
    GIT_SHALLOW TRUE 
    GIT_PROGRESS TRUE # Since the clone process is lengthy, show progress of download
    GIT_SUBMODULES qtbase # The only QT submodule we need
)

# Declaring dependencies via FetchContent_Declare does not make them "available", meaning
# they will not be downloaded nor be installed until we call FetchContent_MakeAvailable()a
# or FetchContent_Populate().
FetchContent_MakeAvailable(qt6)