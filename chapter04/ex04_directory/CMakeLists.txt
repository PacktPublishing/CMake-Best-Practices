# CMakeLists file for the Chapter 4 Example nr. 04: 
# Install directories
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  ch4_ex04_directory
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 04, install directory"
  LANGUAGES CXX)

include(GNUInstallDirs) # Defines the ${CMAKE_INSTALL_INCLUDEDIR} variable.

install(DIRECTORY dir1 DESTINATION ${CMAKE_INSTALL_LOCALSTATEDIR} FILES_MATCHING PATTERN "*.x") 
install(DIRECTORY dir2 DESTINATION ${CMAKE_INSTALL_LOCALSTATEDIR} FILES_MATCHING PATTERN "*.hpp" EXCLUDE PATTERN "*") 
install(DIRECTORY dir3 DESTINATION ${CMAKE_INSTALL_LOCALSTATEDIR} PATTERN "bin" EXCLUDE) 