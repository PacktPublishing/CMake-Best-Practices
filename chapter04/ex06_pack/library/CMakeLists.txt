# CMakeLists file for the Chapter 4 Example nr. 6: 
# CPack example
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  ch4_ex06_library
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 06, CPack example"
  LANGUAGES CXX)

# Define the executable that will consume the ch4_ex05_lib package
add_library(ch4_ex06_library STATIC src/lib.cpp)

# Set the required C++ standard for the target
target_compile_features(ch4_ex06_library PRIVATE cxx_std_11)

# Specify the include directories for the target named `ch4_ex02_static`
target_include_directories(ch4_ex06_library PUBLIC include)

include(GNUInstallDirs) # Defines the ${CMAKE_INSTALL_INCLUDEDIR} variable.

# Make executable target `ch4_ex02_static` installable. As mentioned before
# in Chapter 4 content, this will only install the output artifacts produced by the target.
install(TARGETS ch4_ex06_library)

# Install the header files. Since header files are not listed as output artifacts, they have
# to be installed separately. 
install (
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

