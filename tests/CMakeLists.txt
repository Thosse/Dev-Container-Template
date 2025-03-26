cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER g++)
project(Test_SudokuSolver LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "Unit tests for SudokuSolver"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(GTest REQUIRED)

include_directories("../src")
file(GLOB PRODUCTION_SOURCES "../src/*.cpp")
# Remove main.cpp from the production sources
list(FILTER PRODUCTION_SOURCES EXCLUDE REGEX ".*/main.cpp")

file(GLOB TEST_SOURCES "*.cpp")

add_executable( 
    run_unittests
    ${PRODUCTION_SOURCES}
    ${TEST_SOURCES}
    # ${TEST_STUBS}
)

target_link_libraries(
    run_unittests
    GTest::gtest_main
    GTest::GTest
    pthread
)
