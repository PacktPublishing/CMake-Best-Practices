cmake_minimum_required(VERSION 3.21)

project(
  "ch3.hello_world_standalone"
  VERSION 1.0
  DESCRIPTION
    "A simple C++ project to demonstrate creating a standalone executables"
  LANGUAGES CXX)

# set policy CMP0121 to the old behavior. CMP0121 is a policy that detects if
# index variables for the list() commands are in a valid format this policy was
# introduced with cmake varsion 3.21
cmake_policy(SET CMP0121 OLD)

list(APPEND MYLIST "abc;def;ghi")
list(GET MYLIST "any" OUT_VAR)

# Create a target to build an executable
add_executable(${PROJECT_NAME})
# Add source files to 'hello_world' target
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)
