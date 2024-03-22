
# Chapter 7 example, showing  how to use resource groups for test execution
# The resource definition is in the resources.json in the same directory as this file
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  "ch7_resource_groups"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

enable_testing()  
# Define a test executable
add_executable(ch7_resource_groups)
target_sources(ch7_resource_groups PRIVATE src/main.cpp)
target_compile_features(ch7_resource_groups PRIVATE cxx_std_17)

# Add a test with the following resource needs
# 2 cpus, 500Mb of RAM
# A total of six instances of server resources and 11 instances of client resources
# split into the following groups:
# 1 group of 1 server and 1 client
# 1 groups of 1 server and 2 clients
# four grouos of 1 server and two clients
add_test(NAME resource_test_1 COMMAND ch7_resource_groups)
set_property(TEST resource_test_1 PROPERTY RESOURCE_GROUPS 
    cpus:2,mem_mb:500 
    servers:1,clients:1 
    servers:1,clients:2 
    4,servers:1,clients:2 
 ) 

 # Add a test with the following resource needs
# 2 cpus, 500Mb of RAM
# A total of two instances of server resources and 3 instances of client resources
# split into the following groups:
# 1 group of 1 server and 1 client
# 1 groups of 1 server and 2 clients
add_test(NAME resource_test_2 COMMAND ch7_resource_groups extra_arg)
set_property(TEST resource_test_2 PROPERTY RESOURCE_GROUPS 
    cpus:2,mem_mb:500 
    servers:1,clients:1 
    servers:1,clients:2 
 ) 

 # Add a test with the following resource needs
# 2 cpus, 8096 Mb of RAM
# A total of two instances of server resources and two instances of client resources
# split into the following groups:
# 1 group of 1 server and 1 client
# 1 groups of 1 server and 1 clients
add_test(NAME resource_test_3 COMMAND ch7_resource_groups extra_arg)
set_property(TEST resource_test_3 PROPERTY RESOURCE_GROUPS 
    cpus:2,mem_mb:8096 
    servers:1,clients:1 
    servers:1,clients:1 
 ) 





