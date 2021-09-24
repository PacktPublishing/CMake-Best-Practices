cmake_minimum_required(VERSION 3.21)

project(
  "CMake-Tips-And-Tricks-Chapter3"
  VERSION 1.0
  DESCRIPTION
    "A simple C++ project to demonstrate creating executables and libraries in CMake"
  LANGUAGES CXX)

# Create a target to build an executable
add_executable(hello_world)
# Add source files to 'hello_world' target
target_sources(hello_world PRIVATE src/main.cpp)
