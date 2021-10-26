cmake_minimum_required(VERSION 3.21)
find_library(
    OBSCURE_LIBRARY
    NAMES obscure 
    HINTS ${PROJECT_SOURCE_DIR}/dep/
    PATH_SUFFIXES lib bin build/Release build/Debug
)

find_path(
    OBSCURE_INCLUDE_DIR
    NAMES obscure/obscure.hpp
    HINTS ${PROJECT_SOURCE_DIR}/dep/include/
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
    Obscure
    DEFAULT_MSG
    OBSCURE_LIBRARY
    OBSCURE_INCLUDE_DIR
)

mark_as_advanced(OBSCURE_LIBRARY OBSCURE_INCLUDE_DIR)
message(STATUS "Obscure: ${OBSCURE_LIBRARY} ${OBSCURE_INCLUDE_DIR}")

if(OBSCURE_FOUND
   AND NOT
       TARGET
       Obscure::Obscure
)
    add_library(
        Obscure::Obscure
        UNKNOWN
        IMPORTED
    )
    set_target_properties(
        Obscure::Obscure
        PROPERTIES IMPORTED_LOCATION "${OBSCURE_LIBRARY}"
                   INTERFACE_INCLUDE_DIRECTORIES "${OBSCURE_INCLUDE_DIR}"
    )
endif()
