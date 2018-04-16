cmake_minimum_required (VERSION 2.6)
include_directories ("include")
project (example2)

set(FolderToCheck "../bin")

add_custom_target( bin_folder ALL
    COMMAND test -e ${FolderToCheck} || mkdir ${FolderToCheck}
    COMMENT "Checking if ${FolderToCheck} exists...")

add_executable(${FolderToCheck}/example2 src/example2.cpp )

target_link_libraries (${FolderToCheck}/example2)
