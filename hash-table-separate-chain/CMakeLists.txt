
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(hash-table-separate-chain)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(
    include
)

add_executable(
    hash-table-separate-chain
    src/main.cpp
)