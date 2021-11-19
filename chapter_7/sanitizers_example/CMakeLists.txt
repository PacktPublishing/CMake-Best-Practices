
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_sanitizers"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using various sanitizers"
  LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_ADDRESS_SANITIZER "Enable address sanitizer" OFF)
  option(ENABLE_ADDRESS_SANITIZER_GLOBAL "Enable address sanitizer globally" OFF)
 
endif()
if(ENABLE_ADDRESS_SANITIZER_GLOBAL)
  add_compile_options(-fsanitize=address)
  add_link_options(-fsanitize=address)
endif()
  

enable_testing()
add_executable(ch7_sanitizers)
target_sources(ch7_sanitizers PRIVATE src/main.cpp)
target_compile_options(ch7_sanitizers PRIVATE $<$<BOOL:${ENABLE_ADDRESS_SANITIZER}>:-fsanitize=address>)
target_link_options(ch7_sanitizers PRIVATE $<$<BOOL:${ENABLE_ADDRESS_SANITIZER}>:-fsanitize=address>)

# Since this test contains a memory use after free to illustrate the use of the address sanitizer
# it is not stable and only enabled if the address sanitizer is enabled to show how it is working
if(ENABLE_ADDRESS_SANITIZER OR ENABLE_ADDRESS_SANITIZER_GLOBAL)  
  add_test(NAME sanitizer_test COMMAND ch7_sanitizers)
  # The test will fail because of address sanitizer violations
  set_tests_properties(sanitizer_test PROPERTIES WILL_FAIL True)
endif()