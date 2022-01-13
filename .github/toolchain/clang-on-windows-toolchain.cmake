# Copyied from https://github.com/friendlyanon/cmake-init-clang-on-windows 
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Tell Clang the triplet to target
set(CMAKE_C_COMPILER_TARGET x86_64-pc-windows)
set(CMAKE_CXX_COMPILER_TARGET x86_64-pc-windows)

# https://github.com/actions/virtual-environments/blob/main/images/win/Windows2019-Readme.md#workloads-components-and-extensions
set(windows_kit_version 10.0.21381.0)

# https://github.com/actions/virtual-environments/blob/main/images/win/Windows2019-Readme.md#microsoft-visual-c
set(msvc_version 14.29.30135)

# You have to find it out on your own by running cl.exe, windows-2019 has this one
set(cl_version 19.29.30137)

# Clang needs to use MSVC's system .lib files
add_link_options(
    "LINKER:SHELL:\"/libpath:C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Tools/MSVC/${msvc_version}/lib/x64\""
    "LINKER:SHELL:\"/libpath:C:/Program Files (x86)/Windows Kits/10/Lib/${windows_kit_version}/ucrt/x64\""
    "LINKER:SHELL:\"/libpath:C:/Program Files (x86)/Windows Kits/10/Lib/${windows_kit_version}/um/x64\""
)

# Standard headers
include_directories(
    SYSTEM
    "C:/Program Files (x86)/Microsoft Visual Studio/2019/Enterprise/VC/Tools/MSVC/${msvc_version}/include"
    "C:/Program Files (x86)/Windows Kits/10/include/${windows_kit_version}/ucrt"
    "C:/Program Files (x86)/Windows Kits/10/include/${windows_kit_version}/shared"
    "C:/Program Files (x86)/Windows Kits/10/include/${windows_kit_version}/um"
)

# Tell Clang what version of cl.exe to emulate, so it sets the defines up correctly
add_compile_options("-fms-compatibility-version=${cl_version}")