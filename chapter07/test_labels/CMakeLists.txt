
# Chapter 7 example to showing how tests are labeled
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_test_labels"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

enable_testing()  
add_executable(ch7_test_labels)
target_sources(ch7_test_labels PRIVATE src/main.cpp)

# Label the test test `labeled_test_1 with the label "example"
add_test(NAME labeled_test_1 COMMAND ch7_test_labels)
set_tests_properties(labeled_test_1 PROPERTIES LABELS "example")

# Label the test test `labeled_test_2 with the label "will_fail" and mark 
# that this test is expected to return a non-zero value on success 
add_test(NAME labeled_test_2 COMMAND ch7_test_labels extra_arg)
set_tests_properties(labeled_test_2 PROPERTIES LABELS "will_fail" WILL_FAIL True)

# Label the test test `labeled_test_3 with the label "example" and "will_fail" and mark 
# that this test is expected to return a non-zero value on success 
add_test(NAME labeled_test_3 COMMAND ch7_test_labels extra_arg)
set_tests_properties(labeled_test_3 PROPERTIES LABELS "example;will_fail" WILL_FAIL True)




