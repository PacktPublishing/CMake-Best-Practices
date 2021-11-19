
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_code_coverage"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES
                                            ".*Clang")
  option(ENABLE_COVERAGE "Enable code coverage" ON)
  set(COVERAGE_LINKER_FLAGS --coverage)
  set(COVERAGE_COMPILER_FLAGS --coverage -O0)

endif()
  
enable_testing()
add_library(ch7_code_coverage STATIC)
target_include_directories(ch7_code_coverage PUBLIC include)
target_compile_features(ch7_code_coverage PUBLIC cxx_std_11)
target_link_libraries(ch7_code_coverage INTERFACE $<$<BOOL:${ENABLE_COVERAGE}>:${COVERAGE_LINKER_FLAGS}>)    
target_compile_options(ch7_code_coverage PUBLIC $<$<BOOL:${ENABLE_COVERAGE}>:${COVERAGE_COMPILER_FLAGS}>)
target_sources(ch7_code_coverage PRIVATE src/coverage_example/coverage_example.cpp)


add_executable(ch7_code_coverage_test src/coverage_test.cpp)
target_link_libraries(ch7_code_coverage_test ch7_code_coverage)
target_compile_options(ch7_code_coverage_test PUBLIC $<$<BOOL:${ENABLE_COVERAGE}>:${COVERAGE_COMPILER_FLAGS}>)  

target_compile_features(ch7_code_coverage_test PRIVATE cxx_std_11)
add_test(NAME "code_coverage_test" COMMAND ch7_code_coverage_test)


find_program(GCOVR_EXECUTABLE NAMES gcovr)

if(ENABLE_COVERAGE AND GCOVR_EXECUTABLE)
message(STATUS "Code coverage enabled")
  add_custom_target(coverage_report_html
    COMMAND ${GCOVR_EXECUTABLE} -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generate coverate report")
  
endif()
