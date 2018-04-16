cmake_minimum_required (VERSION 2.6)
include_directories ("include")
project (chessgame)

set(FolderToCheck "../bin")

add_custom_target( bin_folder ALL
    COMMAND test -e ${FolderToCheck} || mkdir ${FolderToCheck}
    COMMENT "Checking if ${FolderToCheck} exists...")

add_executable(${FolderToCheck}/chessgame src/chessgame.cpp src/piece.cpp src/board.cpp )

target_link_libraries (${FolderToCheck}/chessgame)
