
cmake_minimun_required(VERSION 3.8 FATAL_ERROR)

project(graph-data-structure)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    include
)

add_executable(
    graph-data-structure
    src/main.cpp
)