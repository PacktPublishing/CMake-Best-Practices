# CMakeLists file for the Chapter 2 - Component Interface
#
# SPDX-License-Identifier: MIT

project(
    ch2.framework.component_interface
    VERSION 1.0
    DESCRIPTION "Chapter 2 component interface implementation"
    LANGUAGES CXX
)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(
    ${PROJECT_NAME} INTERFACE include/ $<INSTALL_INTERFACE:include>
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

# Make specified target(s) installable. Separate them to components.
install(TARGETS ${PROJECT_NAME} COMPONENT ch2.libraries)

# Install the headers
install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    COMPONENT ch2.libraries
    DESTINATION include
    FILES_MATCHING PATTERN "**/*"
)
