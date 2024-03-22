cmake_minimum_required(VERSION 3.23)


if(CMAKE_ARGC LESS 5)
    message(FATAL_ERROR "Usage: cmake -P CreateSha256.cmake file_to_hash target_file")
endif()

set(FILE_TO_HASH ${CMAKE_ARGV3})
set(TARGET_FILE ${CMAKE_ARGV4})

message(STATUS "Writing sha256 for file '${FILE_TO_HASH}' to file '${TARGET_FILE}'")

# Read the source file and generate the hash for it
file(SHA256 "${FILE_TO_HASH}" GENERATED_HASH)

message(STATUS "sha256 for file '${FILE_TO_HASH}': ${GENERATED_HASH}")
# write the hash to a new file
file(WRITE "${TARGET_FILE}" "${GENERATED_HASH}")