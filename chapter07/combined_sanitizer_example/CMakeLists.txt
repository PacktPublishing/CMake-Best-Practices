
# CMakeLists file for the Chapter 7 example, showing a simple project which executes a test
# 
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)

project(
  "ch7_combined_sanitizers"
  VERSION 1.0
  DESCRIPTION "A simple C++ project to demonstrate using a combined ENABLED_SANITIZERS on an executable"
  LANGUAGES CXX)


if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES
                                            ".*Clang")

  set(ENABLED_SANITIZERS "")
  set(HAS_SANITIZER_FLAGS false)

  option(ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" OFF)
  if(ENABLE_SANITIZER_ADDRESS)
    list(APPEND ENABLED_SANITIZERS "address")
  endif()

  option(ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
  if(ENABLE_SANITIZER_LEAK)
    list(APPEND ENABLED_SANITIZERS "leak")
  endif()

  option(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR
          "Enable undefined behavior sanitizer" OFF)
  if(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR)
    list(APPEND ENABLED_SANITIZERS "undefined")
  endif()

  option(ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
  if(ENABLE_SANITIZER_THREAD)
    if("address" IN_LIST ENABLED_SANITIZERS OR "leak" IN_LIST ENABLED_SANITIZERS)
      message(
        WARNING
          "Thread sanitizer does not work with Address and Leak sanitizer enabled"
      )
    else()
      list(APPEND ENABLED_SANITIZERS "thread")
    endif()
  endif()

  option(ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
  if(ENABLE_SANITIZER_MEMORY AND CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    if("address" IN_LIST ENABLED_SANITIZERS
        OR "thread" IN_LIST ENABLED_SANITIZERS
        OR "leak" IN_LIST ENABLED_SANITIZERS)
      message(
        WARNING
          "Memory sanitizer does not work with Address, Thread and Leak sanitizer enabled"
      )
    else()
      list(APPEND ENABLED_SANITIZERS "memory")
    endif()
  endif()

  list(JOIN ENABLED_SANITIZERS "," LIST_OF_ENABLED_SANITIZERS)

endif()

if(LIST_OF_ENABLED_SANITIZERS AND NOT "${LIST_OF_ENABLED_SANITIZERS}" STREQUAL "")
  set(ENABLED_SANITIZER_FLAGS "-fsanitize=${LIST_OF_ENABLED_SANITIZERS}")
  set(HAS_SANITIZER_FLAGS true)
  
endif()
  

enable_testing()
add_executable(ch7_combined_sanitizers)
target_sources(ch7_combined_sanitizers PRIVATE src/main.cpp)
target_compile_options(ch7_combined_sanitizers PRIVATE $<$<BOOL:${HAS_SANITIZER_FLAGS}>:${ENABLED_SANITIZER_FLAGS}>)
target_link_options(ch7_combined_sanitizers PRIVATE $<$<BOOL:${HAS_SANITIZER_FLAGS}>:${ENABLED_SANITIZER_FLAGS}>)

# Since this test contains a memory use after free to illustrate the use of the address sanitizer
# it is not stable and only enabled if the address sanitizer is enabled to show how it is working
if(ENABLE_ADDRESS_SANITIZER OR ENABLE_ADDRESS_SANITIZER_GLOBAL)  
  add_test(NAME combined_sanitizer_test COMMAND ch7_combined_sanitizers)
  # The test will fail because of address sanitizer violations
  set_tests_properties(combined_sanitizer_test PROPERTIES WILL_FAIL True)
endif()