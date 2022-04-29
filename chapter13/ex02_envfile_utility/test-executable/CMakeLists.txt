# CMakeLists file for the Chapter 11 Example nr. 02:
# Environment file reader CMake module
#
# SPDX-License-Identifier: MIT

project(
  ch13_ex02_envfile_utility_test
  VERSION 1.0
  DESCRIPTION "Chapter 13 Example 02, CMake environment file reader utility module, driver application"
  LANGUAGES CXX)


include(envfile-utils)

read_environment_file("${PROJECT_SOURCE_DIR}/variables.env")

# Define an executable target named `ch13_ex02_envfile_utility_test` 
add_executable(ch13_ex02_envfile_utility_test)
# Specify source files for target named `ch13_ex02_envfile_utility_test`
target_sources(ch13_ex02_envfile_utility_test PRIVATE test.cpp)
# Request compile features for target named `ch13_ex02_envfile_utility_test`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch13_ex02_envfile_utility_test PRIVATE cxx_std_11)

# Expose PROJECT_VERSION and PROJECT_AUTHOR variables as macro definitions
target_compile_definitions(ch13_ex02_envfile_utility_test PRIVATE TEST_PROJECT_VERSION="${TEST_PROJECT_VERSION}" TEST_PROJECT_AUTHOR="${TEST_PROJECT_AUTHOR}")