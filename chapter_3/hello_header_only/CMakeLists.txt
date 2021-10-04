# Chapter 3 - Header only library
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  hello_header_only
  VERSION 1.0
  DESCRIPTION "Chapter 3 header only example"
  LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include/)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
