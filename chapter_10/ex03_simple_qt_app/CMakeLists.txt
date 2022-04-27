# CMakeLists file for the Chapter 10 Example nr. 03: 
# Building a QT project with Superbuild
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21.0)

project(
  ch10_ex03_simple_qt_app
  VERSION 1.0
  DESCRIPTION "Chapter 10 Example 03, Building a QT Project With Superbuild"
  LANGUAGES CXX)

# Adapted from the following example: https://doc.qt.io/qt-5/cmake-get-started.html#build-a-gui-executable

if(CH10_EX03_USE_SUPERBUILD)
  include(superbuild.cmake)
else()
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
    # User decided to not to use superbuild. We have to discover the dependencies
    # from the current environment as usual.
    # We need `Core` and Widgets QT components for our simple QT app.
    find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
endif()

# Define the executable target
add_executable(ch10_ex03_simple_qt_app main.cpp)

# Set C++ standard for the executable
target_compile_features(ch10_ex03_simple_qt_app PRIVATE cxx_std_11)

# Link QT components to the executable
target_link_libraries(ch10_ex03_simple_qt_app Qt6::Core Qt6::Widgets)