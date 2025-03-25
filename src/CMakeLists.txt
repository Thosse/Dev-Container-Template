cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER g++)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


include_directories(src/)

file(GLOB PRODUCTION_SOURCES "*.cpp")

# add_library(Sudoku STATIC ${PRODUCTION_SOURCES})
add_executable(main ${PRODUCTION_SOURCES})