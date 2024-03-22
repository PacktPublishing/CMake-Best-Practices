
# CMakeLists file for the Chapter 7. Example to show how sanitizers can be enabled
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  "ch7_simple_sanitizer"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using a single sanitizer on an executable"
  LANGUAGES CXX)

add_executable(ch7_simple_sanitizer)
target_sources(ch7_simple_sanitizer PRIVATE src/main.cpp)

# Since this test contains a memory use after free to illustrate the use of the address sanitizer
# it is not stable and only enabled if the address sanitizer is enabled to show how it is working
if(ENABLE_ADDRESS_SANITIZER_TEST)  
  add_test(NAME sanitizer_test COMMAND ch7_simple_sanitizer)
  # The test will fail because of address sanitizer violations
  set_tests_properties(sanitizer_test PROPERTIES WILL_FAIL True)
endif()