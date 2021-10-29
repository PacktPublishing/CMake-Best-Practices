# Example code for CMake Best Practices - Chapter 2

The project for this chapter is structured as a framework which contains three CMake targets and example driver application which consumes the framework. The project follows component based design principles.

- The code requires a compiler which understands C++11. The requirement is specified in top-level CMakeLists file via setting `CMAKE_CXX_STANDARD` and `CMAKE_CXX_STANDARD_REQUIRED` variables.
- project() directive in sub-directory CMakeLists are used to eliminate redundant target name specification for a component.
- install() directive in top-level CMakeLists file makes all targets installable.
