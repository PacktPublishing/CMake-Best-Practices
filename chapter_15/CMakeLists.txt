cmake_minimum_required(VERSION 3.21)

project(
    "Migration project"
    VERSION 1.0
    DESCRIPTION
        "A root file for migrating the projects"
    LANGUAGES CXX
)

include(ExternalProject)

set(installDir ${CMAKE_CURRENT_BINARY_DIR}/install)

ExternalProject_Add(microhttpd_ext
    SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/libmicrohttpd-0.9.75/
    INSTALL_DIR ${installDir}
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix <INSTALL_DIR>
    INSTALL_COMMAND make install
    BUILD_COMMAND make
)

add_library(microhttpd::microhttpd IMPORTED SHARED)
set_target_properties(
    microhttpd::microhttpd
    PROPERTIES IMPORTED_LOCATION "${installDir}/lib/libmicrohttpd.so"
               INTERFACE_INCLUDE_DIRECTORIES "${installDir}/include"
               IMPORTED_LINK_INTERFACE_LANGUAGES "CXX")

add_executable(test src/main.cpp)
target_include_directories(test PRIVATE ${installDir}/include)
#target_link_libraries(test microhttpd::microhttpd)