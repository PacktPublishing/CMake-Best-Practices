# CMakeLists file for the Chapter 2 - Component 1
#
# SPDX-License-Identifier: MIT

project(
    ch2_framework_component1
    VERSION 1.0
    DESCRIPTION "Chapter 2 component 1 implementation"
    LANGUAGES CXX
)

add_library(
    ch2_framework_component1 STATIC
) # Create a static library target named ch2_framework_component1 (retrieved
  # from project name variable)
target_include_directories(
  ch2_framework_component1 PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include/
) # Add include/ to include directories with visibility of PUBLIC.
target_sources(
  ch2_framework_component1 PRIVATE src/component1.cpp
) # Add src/component1.cpp file as sources to the target with PRIVATE
  # visibility.
target_link_libraries(
  ch2_framework_component1 PUBLIC ch2_framework_component_interface
)# Link against ch2_framework_component_interface

target_compile_features(ch2_framework_component1 PUBLIC cxx_std_11)

# Make specified target(s) installable. Separate them to components.
install(
    TARGETS ch2_framework_component1
    COMPONENT ch2.libraries
)

# Install the headers
install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    COMPONENT ch2.libraries
    DESTINATION include
)
