# CMakeLists file for the Chapter 4 Example nr. 03: 
# Installable files/programs
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  ch4_ex03_file
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 03, install file/program"
  LANGUAGES CXX)

include(GNUInstallDirs)

install(FILES "${CMAKE_CURRENT_LIST_DIR}/chapter4_greeter_content" DESTINATION "${CMAKE_INSTALL_BINDIR}")
install(PROGRAMS "${CMAKE_CURRENT_LIST_DIR}/chapter4_greeter.py" DESTINATION "${CMAKE_INSTALL_BINDIR}" RENAME chapter4_greeter)