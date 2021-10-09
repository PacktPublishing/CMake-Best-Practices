# CMakeLists file for the Chapter 4 Example nr. 04: 
# Install directories
#
# SPDX-License-Identifier: MIT

project(
  ch4_ex04_directory
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 04, install directory"
  LANGUAGES CXX)

install(DIRECTORY dir1 TYPE LOCALSTATE FILES_MATCHING PATTERN "*.x") 
install(DIRECTORY dir2 TYPE LOCALSTATE FILES_MATCHING PATTERN "*.hpp" EXCLUDE PATTERN "*") 
install(DIRECTORY dir3 TYPE LOCALSTATE PATTERN "bin" EXCLUDE) 