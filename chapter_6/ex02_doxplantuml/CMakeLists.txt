# CMakeLists file for the Chapter 6 Example nr. 01: 
# Doxygen documentation generation
#
# SPDX-License-Identifier: MIT

project(
  ch6_ex02_doxplantuml
  VERSION 1.0
  DESCRIPTION "Chapter 6 Example 02, Doxygen documentation PlantUML generation"
  LANGUAGES CXX)

############################################################################
# Doxygen configuration
############################################################################
# Locate PlantUML JAR file in the environment
find_path(PLANTUML_JAR_PATH NAMES plantuml.jar HINTS "/usr/share/plantuml" "C:/Program Files/PlantUML" "C:/ProgramData/chocolatey/lib/plantuml/tools" "/usr/local/Cellar/plantuml@1.2021.13/1.2021.13/libexec" REQUIRED)

# Locate Doxygen in the environment. This will set DOXYGEN_FOUND variable 
# as a result. When Doxygen is found, DOXYGEN_VERSION variable will be 
# also set to found Doxygen version.
find_package(Doxygen REQUIRED)

# Override the default doxygen output directory, which is CMAKE_CURRENT_BINARY_DIR. 
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs")
# Enable HTML documentation generation
set(DOXYGEN_GENERATE_HTML YES)
# Enable autolink support
set(DOXYGEN_AUTOLINK_SUPPORT YES)
# Tell the Doxygen the PlantUML JAR path
set(DOXYGEN_PLANTUML_JAR_PATH "${PLANTUML_JAR_PATH}")
# Suppress the output messages
set(DOXYGEN_QUIET YES)
############################################################################
# Create an executable target that consumes the library
add_executable(ch6_ex02_doxplantuml src/main.cpp)
# Compile features for the executable target
target_compile_features(ch6_ex02_doxplantuml PRIVATE cxx_std_11)

doxygen_add_docs(
  ch6_ex02_doxdocgen_generate_docs
  "${CMAKE_CURRENT_LIST_DIR}"
  ALL
  COMMENT "Generating documentation for Chapter 6 - Example 02 with Doxygen"
)