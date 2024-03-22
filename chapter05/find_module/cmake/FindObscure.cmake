cmake_minimum_required(VERSION 3.23)

# find the libary file libobscure.so obscure.dll or libobscure.1.0.0.so or similar
# Additionally to the default paths look in ${PROJECT_SOURCE_DIR}/dep/
# in each subdirectory append bin lib build/Release and build/Debug
find_library(
    OBSCURE_LIBRARY
    NAMES obscure 
    HINTS ${PROJECT_SOURCE_DIR}/dep/ ${CMAKE_CURRENT_BINARY_DIR}/dep
    PATH_SUFFIXES lib bin build/Release build/Debug 
)

# find the main header belonging to the obscure lib
find_path(
    OBSCURE_INCLUDE_DIR
    NAMES obscure/obscure.hpp
    HINTS ${PROJECT_SOURCE_DIR}/dep/include/ ${CMAKE_CURRENT_BINARY_DIR}/dep/include ${CMAKE_CURRENT_SOURCE_DIR}/dep_source/include
)

# use the FindPackageHandleStandardArgs to check if everything was found
include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
    Obscure
    DEFAULT_MSG
    OBSCURE_LIBRARY
    OBSCURE_INCLUDE_DIR
)

mark_as_advanced(OBSCURE_LIBRARY OBSCURE_INCLUDE_DIR)

# if not building the library itself
if(NOT TARGET Obscure::Obscure)
    
    # make the library target available
    add_library(Obscure::Obscure UNKNOWN IMPORTED)
    
    # set the properties so the artifacts of the packages can be found
    set_target_properties(
        Obscure::Obscure
        PROPERTIES IMPORTED_LOCATION "${OBSCURE_LIBRARY}"
                   INTERFACE_INCLUDE_DIRECTORIES "${OBSCURE_INCLUDE_DIR}"
                   IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
    )
endif()
