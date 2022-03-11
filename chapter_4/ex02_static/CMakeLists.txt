# CMakeLists file for the Chapter 4 Example nr. 02: 
# Installable static library
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch4_ex02_static
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 02, installable static library project"
  LANGUAGES CXX)

# Define an executable target named `ch4_ex02_static` 
add_library(ch4_ex02_static STATIC)
# Specify source files for target named `ch4_ex02_static`
target_sources(ch4_ex02_static PRIVATE src/lib.cpp)
# Specify the include directories for the target named `ch4_ex02_static`
target_include_directories(ch4_ex02_static PUBLIC include)
# Request compile features for target named `ch4_ex02_static`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch4_ex02_static PRIVATE cxx_std_11)
include(GNUInstallDirs) # Defines the ${CMAKE_INSTALL_INCLUDEDIR} variable.
# Make executable target `ch4_ex02_static` installable. As mentioned before
# in Chapter 4 content, this will only install the output artifacts produced by the target.
install(TARGETS ch4_ex02_static)
# Install the header files. Since header files are not listed as output artifacts, they have
# to be installed separately. 
install (
    DIRECTORY include/
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)
