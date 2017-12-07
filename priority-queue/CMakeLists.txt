
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project( priority-queue )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories (
    include
)

add_executable(
    priority-queue
    src/main.cpp
)