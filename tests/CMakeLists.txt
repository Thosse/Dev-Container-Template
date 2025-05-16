
find_package(GTest REQUIRED)

file(GLOB TEST_SOURCES "*.cpp")

add_executable( 
    sudoku_tests
    ${TEST_SOURCES}
)

target_link_libraries(
    sudoku_tests
    PRIVATE sudoku_solver
    PRIVATE GTest::gtest_main
)

gtest_discover_tests(sudoku_tests)
