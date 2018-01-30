
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(binary-tree)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(
    include
)

add_executable(
    binary-tree
    src/main.cpp
)