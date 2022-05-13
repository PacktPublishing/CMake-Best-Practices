# Top-level CMakeLists file for the Chapter 7 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
    "Chapter_7"
    VERSION 1.0
    DESCRIPTION
        "A collection of sample C++ projects to demonstrate testing, code coverage and static code analysis"
    LANGUAGES CXX
)

add_subdirectory(simple_test)
add_subdirectory(test_labels)
add_subdirectory(pass_fail_criteria)
add_subdirectory(timeout_example)
add_subdirectory(simple_sanitizer_example)
add_subdirectory(cppcheck_example)
add_subdirectory(cpplint_example)
add_subdirectory(clang_tidy_example)
add_subdirectory(iwyu_example)
add_subdirectory(lwyu_example)
add_subdirectory(test_discovery_example)
add_subdirectory(fixture_example)
add_subdirectory(resource_group_example)
add_subdirectory(custom_build_type)