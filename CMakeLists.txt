cmake_minimum_required(VERSION 3.25)
project(SudokuSolver VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Build the library
add_subdirectory(src)
# Build the application
add_executable(sudoku_app main.cpp)
target_link_libraries(sudoku_app PRIVATE sudoku_solver)

# Enable testing at the top level
enable_testing()
# Add the test directory
add_subdirectory(tests)
