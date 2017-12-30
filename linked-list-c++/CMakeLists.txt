
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(linked-list)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(
    include
)

add_executable(
    linked-list
    src/main.cpp
    src/LinkedList.cpp
)