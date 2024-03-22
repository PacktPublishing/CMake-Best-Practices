cmake_minimum_required(VERSION 3.23)


if(CMAKE_ARGC LESS 5)
    message(FATAL_ERROR "Usage: cmake -P WriteMain.cmake message_file target_file")
endif()

set(MESSAGE_FILE ${CMAKE_ARGV3})
set(TARGET_FILE ${CMAKE_ARGV4})

file(READ ${MESSAGE_FILE} MESSAGE)

set(MAIN_CC_CODE "
#include <iostream>
int main() {
    std::cout << \"${MESSAGE}\";
}
"
)

# write the hash to a new file
file(WRITE "${TARGET_FILE}" "${MAIN_CC_CODE}")