
cmake_minimum_required( VERSION 3.8 FATAL_ERROR )

project ( insertion-sort-benchmark )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

include_directories(
    include
)

add_executable(
    insertion-sort-benchmark
    src/main.cpp
)