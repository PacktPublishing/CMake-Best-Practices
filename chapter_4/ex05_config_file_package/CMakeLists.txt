# CMakeLists file for the Chapter 4 Example nr. 01: 
# Installable executable
#
# SPDX-License-Identifier: MIT

project(
  ch4_ex05_lib
  VERSION 1.0
  DESCRIPTION "Chapter 4 Example 05, Config-file package"
  LANGUAGES CXX)


include(GNUInstallDirs) # Defines the ${CMAKE_INSTALL_INCLUDEDIR} variable.

set (ch4_ex05_lib_INCLUDE_DIRS "include")

set(DEF_INSTALL_CMAKE_DIR cmake)

set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

# Define a static library target named `ch4_ex05_lib` 
add_library(ch4_ex05_lib STATIC)
# Specify source files for target named `ch4_ex05_lib`
target_sources(ch4_ex05_lib PRIVATE src/lib.cpp)
# Specify the include directories for the target named `ch4_ex05_lib`
target_include_directories(ch4_ex05_lib PUBLIC 
          $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
          $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Specify the public headers for the target named `ch4_ex05_lib`
# By default, CMake does not install any extra files other than output artifacts
# for the target. In order to install the header files too, target's PUBLIC_HEADER property 
# must be populated
set_target_properties(ch4_ex05_lib PROPERTIES PUBLIC_HEADER include/chapter4/ex05/lib.hpp)
# Request compile features for target named `ch4_ex05_lib`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch4_ex05_lib PRIVATE cxx_std_11)
# Make executable target `ch4_ex05_lib` installable. As mentioned before
# in Chapter 4 content, this will only install the output artifacts produced by the target.
# Since we want to preserve the folder structure, we have to override the PUBLIC_HEADER 
# path with our header path.
install(TARGETS ch4_ex05_lib
        EXPORT ch4_ex05_lib
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/chapter4/ex05
)

install(EXPORT ch4_ex05_lib
        FILE ch4_ex05_lib-config.cmake
        NAMESPACE ch4_ex05_lib::
        DESTINATION ${INSTALL_CMAKE_DIR}
)

# Defines write_basic_package_version_file & configure_package_config_file
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/ch4_ex05_lib-config-version.cmake"
  VERSION 1.0.1
  COMPATIBILITY SameMajorVersion
)

# Install command for deploying Config-file package files into the target system
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/ch4_ex05_lib-config-version.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}")

# See ex05_consumer

