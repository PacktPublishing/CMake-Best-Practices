# CMakeLists file for the Chapter 6 Example nr. 01: 
# Doxygen documentation generation
#
# SPDX-License-Identifier: MIT

project(
  ch6_ex01_doxdocgen
  VERSION 1.0
  DESCRIPTION "Chapter 6 Example 01, Doxygen documentation generation"
  LANGUAGES CXX)

############################################################################
# Doxygen configuration
############################################################################
# Locate Doxygen in the environment. This will set DOXYGEN_FOUND variable 
# as a result. When Doxygen is found, DOXYGEN_VERSION variable will be 
# also set to found Doxygen version.
find_package(Doxygen REQUIRED)

# Override the default doxygen output directory, which is CMAKE_CURRENT_BINARY_DIR. 
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs")
# Enable HTML documentation generation
set(DOXYGEN_GENERATE_HTML YES)
# Enable MAN page generation
set(DOXYGEN_GENERATE_MAN YES)
# Enable markdown support
set(DOXYGEN_MARKDOWN_SUPPORT YES)
# Enable autolink support
set(DOXYGEN_AUTOLINK_SUPPORT YES)
# Enable dot graph support
set(DOXYGEN_HAVE_DOT YES)
# Include collaboration diagrams in class documentation
set(DOXYGEN_COLLABORATION_GRAPH NO)
# Include class diagrams in class documentation
set(DOXYGEN_CLASS_GRAPH YES)
# Generate UML-like graphs
set(DOXYGEN_UML_LOOK YES)
# Include type and parameter information in UML graphs
set(DOXYGEN_DOT_UML_DETAILS YES)
# Max per-line length for graph content
set(DOXYGEN_DOT_WRAP_THRESHOLD 100)
# Enables drawing call graphs for the functions
set(DOXYGEN_CALL_GRAPH YES)
# Suppress the output messages
set(DOXYGEN_QUIET YES)
############################################################################
# Define an static library target named `ch6_ex01_doxdocgen_lib` 
add_library(ch6_ex01_doxdocgen_lib STATIC)
# Specify source files for target named `ch6_ex01_doxdocgen_lib`
target_sources(ch6_ex01_doxdocgen_lib PRIVATE src/calculator.cpp)
# Specify the include directories for the target named `ch6_ex01_doxdocgen_lib`
target_include_directories(ch6_ex01_doxdocgen_lib PUBLIC include)
# Request compile features for target named `ch6_ex01_doxdocgen_lib`.
# Requested `cxx_std_11` feature determines the minimum C++ standard required
# to build this target. It's PRIVATE, since it is a build-time requirement only.
target_compile_features(ch6_ex01_doxdocgen_lib PRIVATE cxx_std_11)
# Create an executable target that consumes the library
add_executable(ch6_ex01_doxdocgen_exe src/main.cpp)
# Compile features for the executable target
target_compile_features(ch6_ex01_doxdocgen_exe PRIVATE cxx_std_11)
# Link static library to executable
target_link_libraries(ch6_ex01_doxdocgen_exe PRIVATE ch6_ex01_doxdocgen_lib)

doxygen_add_docs(
  ch6_ex01_doxdocgen_generate_docs
  "${CMAKE_CURRENT_LIST_DIR}"
  ALL
  COMMENT "Generating documentation for Chapter 6 - Example 01 with Doxygen"
)


# End of core example, rest of the code is related to the packaging part

# Default paths for installation
include(GNUInstallDirs)

# Install the HTML documentation to system's default documentation folder 
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs/html/" DESTINATION "${CMAKE_INSTALL_DOCDIR}" COMPONENT ch6_ex01_html)

# Install the MAN pages to man3 folder, since we're documenting a `library`.
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs/man/" DESTINATION "${CMAKE_INSTALL_MANDIR}" COMPONENT ch6_ex01_man)

# Override the package name
set(CPACK_PACKAGE_NAME cbp_chapter6_example01)
# We will not explicitly specify project name and version here and 
# let CPack to get project name and version from the project()
set(CPACK_PACKAGE_VENDOR "CBP Authors")
# Enable DEB, RPM and TBZ2 generators by default
set(CPACK_GENERATOR "DEB;RPM;TBZ2")
# The DEB generator requires CPACK_DEBIAN_PACKAGE_MAINTAINER
# value to be set.
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "CBP Authors")

# Enable packaging support for the project
include(CPack)
