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
# Specify the public headers for the target named `ch4_ex02_static`
# By default, CMake does not install any extra files other than output artifacts
# for the target. In order to install the header files too, target's PUBLIC_HEADER property 
# must be populated
set_target_properties(ch4_ex06_library PROPERTIES PUBLIC_HEADER include/chapter4/ex06/lib.hpp)

include(GNUInstallDirs) # Defines the ${CMAKE_INSTALL_INCLUDEDIR} variable.

# Make executable target `ch4_ex02_static` installable. As mentioned before
# in Chapter 4 content, this will only install the output artifacts produced by the target.
# Since we want to preserve the folder structure, we have to override the PUBLIC_HEADER 
# path with our header path.
install(TARGETS ch4_ex06_library
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/chapter4/ex06
)
