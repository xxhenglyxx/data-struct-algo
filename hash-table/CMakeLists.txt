
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(hash-table)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(
    include
)

add_executable(
    hash-table
    src/main.cpp
)