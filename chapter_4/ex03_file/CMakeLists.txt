# CMakeLists file for the Chapter 4 Example nr. 01: 
# Installable executable
#
# SPDX-License-Identifier: MIT

project(
  ch4_ex03_file
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 03, install file"
  LANGUAGES CXX)

install(FILES ${CMAKE_CURRENT_LIST_DIR}/chapter4_greeter_content TYPE BIN)
install(PROGRAMS ${CMAKE_CURRENT_LIST_DIR}/chapter4_greeter.py TYPE BIN RENAME chapter4_greeter)