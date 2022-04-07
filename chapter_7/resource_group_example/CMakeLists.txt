
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_resource_groups"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

enable_testing()  
add_executable(ch7_resource_groups)
target_sources(ch7_resource_groups PRIVATE src/main.cpp)
target_compile_features(ch7_resource_groups PRIVATE cxx_std_17)

add_test(NAME resource_test_1 COMMAND ch7_resource_groups)
set_property(TEST resource_test_1 PROPERTY RESOURCE_GROUPS 
    cpus:2,mem_mb:500 
    servers:1,clients:1 
    servers:1,clients:2 
    4,servers:1,clients:2 
 ) 

add_test(NAME resource_test_2 COMMAND ch7_resource_groups extra_arg)
set_property(TEST resource_test_2 PROPERTY RESOURCE_GROUPS 
    cpus:2,mem_mb:500 
    servers:1,clients:1 
    servers:1,clients:2 
 ) 

add_test(NAME resource_test_3 COMMAND ch7_resource_groups extra_arg)
set_property(TEST resource_test_3 PROPERTY RESOURCE_GROUPS 
    cpus:2,mem_mb:8096 
    servers:1,clients:1 
    servers:1,clients:1 
 ) 





