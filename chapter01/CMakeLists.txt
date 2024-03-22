# Top-level CMakeLists file for the Chapter 1 example content.
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.23)

project(
    chapter_1
    VERSION 1.0
    DESCRIPTION
        "Examples for chapter 1 of the CMake Best Practices book"
    LANGUAGES CXX
)

# Add subdirectories with a simple executable
add_subdirectory(simple_executable)
add_subdirectory(policy_example)


option(CHAPTER1_PRINT_LANGUAGE_EXAMPLES "Print examples for each language" OFF)
include(CMakeDependentOption)
# create an option CHAPTER1_PRINT_HELLO_WORLD that is only visible of CHAPTER1_PRINT_LANGUAGE_EXAMPLES is set to ON
cmake_dependent_option(CHAPTER1_PRINT_HELLO_WORLD "Print a nice greeting from chapter1" ON CHAPTER1_PRINT_LANGUAGE_EXAMPLES ON)
mark_as_advanced(CHAPTER1_PRINT_LANGUAGE_EXAMPLES)

if(CHAPTER1_PRINT_LANGUAGE_EXAMPLES)
    if(CHAPTER1_PRINT_HELLO_WORLD)
        message(STATUS "Chapter1: welcome to chapter 1!")
    endif()
    #examples for list operations
    set(MYLIST abc def ghi) 
    message(STATUS "Chapter1: MYLIST is: ${MYLIST}")
    set(MYLIST "abc;def;ghi") 
    message(STATUS "Chapter1: MYLIST is: ${MYLIST}")
    list(APPEND MYLIST "xyz") 
    message(STATUS "Chapter1: MYLIST is: ${MYLIST}")

    list(FIND MYLIST def ABC_INDEX) 
    list(GET MYLIST ${ABC_INDEX} ABC) 
    message(STATUS "Chapter1: Index of 'def' in MYLIST is ${ABC_INDEX} the value at the index is '${ABC}'")

    # add MYVAR as cache variable with the value foo
    set(ch1_MYVAR foo CACHE STRING "Variable foo that configures bar")

    # set a property for this directory
    set_property(DIRECTORY PROPERTY CHAPTER1_PROPERTY "Hello from chapter 1")
    get_property(CH1_PROPERTY_VARIABLE DIRECTORY PROPERTY CHAPTER1_PROPERTY)
    message(STATUS "Chapter1: Property value for CHAPTER1_PROPERTy is '${CH1_PROPERTY_VARIABLE}'")

    # loop examples
    set(MYVAR 0)
    while(MYVAR LESS "5") 
        message(STATUS "Chapter1: MYVAR is '${MYVAR}'")
        math(EXPR MYVAR "${MYVAR}+1") 
    endwhile() 

    foreach(ITEM IN LISTS MYLIST) 
        message(STATUS "Chapter1: ITEM from MYLIST is '${ITEM}'")
    endforeach() 

    foreach(ITEM RANGE 0 5) 
        message(STATUS "Chapter1: ITEM from RANGE is '${ITEM}'")
    endforeach() 

    # function example
    function(foo ARG1) 
        message(STATUS "Chapter1: foo called with '${ARG1}'")
    endfunction() 

    # invoke foo with parameter bar 
    foo(“bar”) 
endif()