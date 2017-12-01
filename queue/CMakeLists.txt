
cmake_minimum_required( VERSION 3.8 FATAL_ERROR )

project ( queue )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

include_directories(
    include
)

add_executable(
    queue
    src/main.cpp
)