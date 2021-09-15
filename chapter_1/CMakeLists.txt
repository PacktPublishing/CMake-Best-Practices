cmake_minimum_required(VERSION 3.21)

project(
  "CMake Tips and Tricks Chapter 1"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

add_executable(Chapter1)
target_sources(Chapter1 PRIVATE src/main.cpp)
