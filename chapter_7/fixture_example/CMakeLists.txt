
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_fixture_sample"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate how test fixtures can be run."
  LANGUAGES CXX)

add_executable(ch7_fixture_sample)
target_sources(ch7_fixture_sample PRIVATE src/main.cpp)

add_executable(ch7_fixture_server)
target_sources(ch7_fixture_server PRIVATE src/server.cpp)

add_test(NAME start_server COMMAND ch7_fixture_server)
set_tests_properties(start_server PROPERTIES FIXTURES_SETUP ch7_server)
add_test(NAME stop_server COMMAND ch7_fixture_server --stop)
set_tests_properties(stop_server PROPERTIES FIXTURES_CLEANUP ch7_server)

add_test(NAME ch7_fixture_test COMMAND ch7_fixture_sample)
set_tests_properties(ch7_fixture_test PROPERTIES FIXTURES_REQUIRED ch7_server)

