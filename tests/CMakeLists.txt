
find_package(GTest REQUIRED)

file(GLOB TEST_SOURCES "*.cpp")

add_executable( 
    sudoku_tests
    ${TEST_SOURCES}
    # ${TEST_STUBS}
)

target_link_libraries(
    sudoku_tests
    PRIVATE sudoku_solver
    PRIVATE GTest::gtest_main
    PRIVATE GTest::GTest
    PRIVATE pthread
)
