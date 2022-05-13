Main Page {#mainpage}
=========

# Chapter 6 - Example 01

This example is intended to illustrate integration between CMake and the Doxygen.

## Project structure

Project contains a static library and an executable target. Static library consist of two header files and one source file (@ref include/chapter6/ex01/calculator.hpp "calculator.hpp", @ref include/chapter6/ex01/calculator_interface.hpp "calculator_interface.hpp", @ref src/calculator.cpp "calculator.cpp"), whereas executable only contains a single source file (@ref src/main.cpp "main.cpp").

### Static library (ch6_ex01_doxdocgen_lib)

An example library that provides a class named @ref chapter6::ex01::calculator "calculator" . This class contains four static functions named @ref chapter6::ex01::calculator::sum "sum(...)", @ref chapter6::ex01::calculator::sub "sub(...)", @ref chapter6::ex01::calculator::div "div(...)", @ref chapter6::ex01::calculator::mul "mul(...)", and a member variable named @ref chapter6::ex01::calculator::last_result "last_result", which keeps the result of the last performed operation. In order to be able to illustrate documentation generation, functions and variables are properly documented in Doxygen JavaDoc format.

### Example application(ch6_ex01_doxdocgen_exe)

The application that consumes the @ref chapter6::ex01::calculator "calculator" class and prints basic four arithmetic operation outputs to the stdout. Example application is not important for this example's purpose. It is included for completeness.
