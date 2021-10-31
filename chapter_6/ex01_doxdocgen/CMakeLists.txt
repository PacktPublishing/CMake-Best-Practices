# CMakeLists file for the Chapter 6 Example nr. 01: 
# Doxygen documentation generation
#
# SPDX-License-Identifier: MIT

project(
  ch6_ex01_doxdocgen
  VERSION 1.0
  DESCRIPTION "Chapter 6 Example 01, Doxygen documentation generation"
  LANGUAGES CXX)

# Define an executable target named `ch4_ex02_static` 
add_library(ch6_ex01_doxdocgen_lib STATIC)
# Specify source files for target named `ch4_ex02_static`
target_sources(ch6_ex01_doxdocgen_lib PRIVATE src/lib.cpp)
# Specify the include directories for the target named `ch4_ex02_static`
target_include_directories(ch6_ex01_doxdocgen_lib PUBLIC include)
# Request compile features for target named `ch4_ex02_static`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch6_ex01_doxdocgen_lib PRIVATE cxx_std_11)


add_executable(ch6_ex01_doxdocgen_exe src/main.cpp)
target_compile_features(ch6_ex01_doxdocgen_exe PRIVATE cxx_std_11)
target_link_libraries(ch6_ex01_doxdocgen_exe PRIVATE ch6_ex01_doxdocgen_lib)


