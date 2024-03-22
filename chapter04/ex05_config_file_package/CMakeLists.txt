# CMakeLists file for the Chapter 4 Example nr. 05: 
# Config-file package
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
  ch4_ex05_lib
  VERSION 1.0.1
  DESCRIPTION "Chapter 4 Example 05, Config-file package"
  LANGUAGES CXX)


include(GNUInstallDirs) # Defines the ${CMAKE_INSTALL_INCLUDEDIR} variable.

# This is the default install directory for config-file package cmake files
# It is relative to install prefix.
set(ch4_ex05_lib_INSTALL_CMAKEDIR cmake CACHE PATH "Installation directory for config-file package cmake files")

# Define a static library target named `ch4_ex05_lib` 
add_library(ch4_ex05_lib STATIC)

# Specify source files for target named `ch4_ex05_lib`
target_sources(ch4_ex05_lib PRIVATE src/lib.cpp)

# Specify the include directories for the target named `ch4_ex05_lib`
target_include_directories(ch4_ex05_lib PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Request compile features for target named `ch4_ex05_lib`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch4_ex05_lib PUBLIC cxx_std_11)

## Until now, it is just regular target definition ... interesting stuff begins after this line

# Make executable target `ch4_ex05_lib` installable. As mentioned before
# in Chapter 4 content, this will only install the output artifacts produced by the target.
install(TARGETS ch4_ex05_lib
        EXPORT ch4_ex05_lib_export # Associate installed target files of the targets in TARGETS parameter with export name of ch4_ex05_lib_export
                                   # Note that this does not export anything yet, it just defines a name and context for the exports. The install(EXPORT)
                                   # call does the actual target exporting.
        # Will be appended to INTERFACE_INCLUDE_DIRECTORIES of exported targets.
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install the header files. Since header files are not listed as output artifacts, they have
# to be installed separately. 
install (
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Generate the required import code for the content in <export name> 
# into ch4_ex05_lib-config.cmake CMake file. Prefix all target names with
# ch4_05_lib:: while doing so (NAMESPACE). DESTINATION argument recommended to be a path
# that will be picked by find_package() by default ('cmake' in our example). 
install(EXPORT ch4_ex05_lib_export
        FILE ch4_ex05_lib-config.cmake
        NAMESPACE ch4_ex05_lib::
        DESTINATION ${ch4_ex05_lib_INSTALL_CMAKEDIR}
)

# Defines write_basic_package_version_file
include(CMakePackageConfigHelpers)

# Create a package version file for the package. This will allow consumers to specify
# version argument to select between several versions of the package via specifying VERSION argument
# to find_package().
# We're not explicitly specifying the VERSION parameter to allow `write_basic_package_version_file` to 
# get it from project(...) version (which is 1.0.1)
write_basic_package_version_file(
  "ch4_ex05_lib-config-version.cmake"
  # Package compatibility strategy. SameMajorVersion is essentially `semantic versioning`.
  COMPATIBILITY SameMajorVersion
)

# Install command for deploying Config-file package files into the target system. It must be present
# in the same directory as `ch4_ex05_lib-config.cmake` file.
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/ch4_ex05_lib-config-version.cmake"
  DESTINATION "${ch4_ex05_lib_INSTALL_CMAKEDIR}"
)

# See ex05_consumer for an example of how to consume the package created here.

