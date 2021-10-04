# CMakeLists file for the Chapter 2 - Component Interface
#
# SPDX-License-Identifier: MIT

project(
    ch2_framework_component_interface
    VERSION 1.0
    DESCRIPTION "Chapter 2 component interface implementation"
    LANGUAGES CXX
)

add_library(ch2_framework_component_interface INTERFACE)
target_include_directories(
  ch2_framework_component_interface INTERFACE include/
)

target_compile_features(ch2_framework_component_interface INTERFACE cxx_std_11)

# Make specified target(s) installable. Separate them to components.
install(TARGETS ch2_framework_component_interface COMPONENT ch2.libraries)

# Install the headers
install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    COMPONENT ch2.libraries
    DESTINATION include
)
