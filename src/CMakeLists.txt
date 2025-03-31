
file(GLOB PRODUCTION_SOURCES "*.cpp")


add_library(sudoku_solver STATIC ${PRODUCTION_SOURCES})

target_include_directories(
    sudoku_solver
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)