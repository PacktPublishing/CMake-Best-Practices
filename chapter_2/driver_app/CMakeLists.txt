# CMakeLists file for the Chapter 2 - Driver Application
#
# SPDX-License-Identifier: MIT

# Project directive is used for creating a child project for the targets we're
# going to create for the component. This will allow us to use project()
# variables in target creation.
project(
  ch2_driver_application
  VERSION 1.0
  DESCRIPTION "Chapter 2 driver application implementation"
  LANGUAGES CXX)

add_executable(
  ch2_driver_application) # Create an executable target named with the same name as
                   # project name (ch2.driver_application)
target_sources(ch2_driver_application PRIVATE src/main.cpp) # Add src/main.cpp as
                                                     # source to the target
target_link_libraries(
  ch2_driver_application PRIVATE ch2_framework_component1 ch2_framework_component2
)# Link target against ch2_framework_component1 and ch2_framework_component2

target_compile_features(ch2_driver_application PUBLIC cxx_std_11)

install(
  TARGETS ch2_driver_application
  COMPONENT ch2.executables
)

