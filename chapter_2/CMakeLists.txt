# Top-level CMakeLists file for the Chapter 2 example content.
#
# SPDX-License-Identifier: MIT

project(
  "CMake Tips and Tricks Chapter 2"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
  LANGUAGES CXX)

# Set C++ standard to 11 for all subdirectories (component1, component2,
# driver_app) in this folder.
set(CMAKE_CXX_STANDARD 11)
# Make C++ 11 standard a must. Setting CMAKE_CXX_STANDARD is a *should* by
# default. When this variable is set and selected compiler does not support
# C++11, the CMake configure step will fail.
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Option to exclude driver application from build.
set(CHAPTER2_BUILD_DRIVER_APPLICATION
    TRUE
    CACHE BOOL "Whether to include driver application in build. Default: True")
# Hide this option from GUI's by default.
mark_as_advanced(CHAPTER2_BUILD_DRIVER_APPLICATION)

# MSVC requires these two flags to be set in order to link driver executable
# against shared library
if(MSVC)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
  set(BUILD_SHARED_LIBS TRUE)
endif()

add_subdirectory(component_interface)
add_subdirectory(component1)
add_subdirectory(component2)

# Include driver_app subdirectory if CHAPTER2_BUILD_DRIVER_APPLICATION flag is
# enabled.
if(CHAPTER2_BUILD_DRIVER_APPLICATION)
  add_subdirectory(driver_app)
endif()

# Make specified target(s) installable. Separate them to components.
install(
  TARGETS ch2.framework.component_interface ch2.framework.component1
          ch2.framework.component2
  COMPONENT libraries
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  PUBLIC_HEADER DESTINATION include
  PRIVATE_HEADER DESTINATION include)
# Check whether target ch2.driver_application exist first. Because, install()
# directive without a present target would not make sense.
if(TARGET ch2.driver_application)
  install(
    TARGETS ch2.driver_application
    COMPONENT executables
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
    PRIVATE_HEADER DESTINATION include)
endif()
