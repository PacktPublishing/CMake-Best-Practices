# CMakeLists file for the Chapter 2 - Component 1
#
# SPDX-License-Identifier: MIT

project(
  ch2.framework.component1
  VERSION 1.0
  DESCRIPTION "Chapter 2 component 1 implementation"
  LANGUAGES CXX)

add_library(
  ${PROJECT_NAME} STATIC) # Create a static library target named
                          # ch2.framework.component1 (retrieved from project
                          # name variable)
target_include_directories(
  ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/) # Add include/ to
                                                         # include directories
                                                         # with visibility of
                                                         # PUBLIC.
target_sources(
  ${PROJECT_NAME} PRIVATE src/component1.cpp) # Add src/component1.cpp file as
                                              # sources to the target with
                                              # PRIVATE visibility.
target_link_libraries(${PROJECT_NAME} PUBLIC ch2.framework.component_interface
)# Link against ch2.framework.component_interface
