
# CMakeLists file for the Chapter 7. Example to show how to use test fixtures
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_fixture_sample"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate how test fixtures can be run."
  LANGUAGES CXX)

include(CTest)

# This executable will be the unit under test
add_executable(ch7_fixture_sample)
target_sources(ch7_fixture_sample PRIVATE src/main.cpp)

# define an executable as fixture
add_executable(ch7_fixture_server)
target_sources(ch7_fixture_server PRIVATE src/server.cpp)

# The comand to start the server is added as a test and then marked as 
# setup function for the fixture named ch7_server
add_test(NAME start_server COMMAND ch7_fixture_server)
set_tests_properties(start_server PROPERTIES FIXTURES_SETUP ch7_server)

# The command to stop the server is added as a test and then marked as a
# cleanup function for the fixture named ch7_server
add_test(NAME stop_server COMMAND ch7_fixture_server --stop)
set_tests_properties(stop_server PROPERTIES FIXTURES_CLEANUP ch7_server)

# Define the test for the unit under test and tell CMake
# that the fixture 'ch7_server' is required to run it
add_test(NAME ch7_fixture_test COMMAND ch7_fixture_sample)
set_tests_properties(ch7_fixture_test PROPERTIES FIXTURES_REQUIRED ch7_server)

