# Chapter 3 - Header only library
#
# @file     CMakeLists.txt @author   Dominik Berner <dominik.berner@gmail.com>
# @date     19.09.2021
#
# SPDX-License-Identifier: MIT
# ______________________________________________________

project(
  ch3.hello_header_only
  VERSION 1.0
  DESCRIPTION "Chapter 3 header only example"
  LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include/)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
