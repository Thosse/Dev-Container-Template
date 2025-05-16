cmake_minimum_required(VERSION 3.25)
project(SudokuSolver VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Add sudoku_solver (static library) to the build projects
add_subdirectory(src)

# Build the application
add_executable(sudoku_app main.cpp)
target_link_libraries(sudoku_app PRIVATE sudoku_solver)

# Autobuild required libraries 
add_dependencies(sudoku_app sudoku_solver)

# Enable testing at the top level
enable_testing()
# Add the tests to the build project
add_subdirectory(tests)

# Doxygen Documentation
add_subdirectory(doc)