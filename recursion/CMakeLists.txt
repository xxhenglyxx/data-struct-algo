
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(recursion)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    include
)

add_executable(
    recursion
    src/main.cpp
)