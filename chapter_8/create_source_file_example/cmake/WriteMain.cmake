cmake_minimum_required(VERSION 3.21)


if(CMAKE_ARGC LESS 4)
    message(FATAL_ERROR "Usage: cmake -P WriteMain.cmake target_file")
endif()

set(TARGET_FILE ${CMAKE_ARGV3})

set(MAIN_CC_CODE "int main() {}")

# write the hash to a new file
file(WRITE "${TARGET_FILE}" "${MAIN_CC_CODE}")