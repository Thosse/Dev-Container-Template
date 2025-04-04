
#include "SudokuIndex.hpp"
#include "Definitions.hpp"
#include <gtest/gtest.h>
#include <cstdint>
#include <stdexcept>

// Test Constructors
TEST(SudokuIndexTest, constructor_valid_on_minimal_values) {
    Sudoku::Index index(Sudoku::MIN_ROW, Sudoku::MIN_COLUMN);
    EXPECT_EQ(index.row, Sudoku::MIN_ROW);
    EXPECT_EQ(index.column, Sudoku::MIN_COLUMN);
}

TEST(SudokuIndexTest, constructor_valid_on_maximal_values)
{
    Sudoku::Index index(Sudoku::MAX_ROW, Sudoku::MAX_COLUMN);
    EXPECT_EQ(index.row, Sudoku::MAX_ROW);
    EXPECT_EQ(index.column, Sudoku::MAX_COLUMN);
}

TEST(SudokuIndexTest, constructor_invalid_on_too_high_row)
{
    EXPECT_THROW(
        Sudoku::Index index(Sudoku::ROW_SIZE, Sudoku::MIN_COLUMN),
        std::out_of_range);
}

TEST(SudokuIndexTest, constructor_invalid_on_too_high_column)
{
    EXPECT_THROW(
        Sudoku::Index index(Sudoku::MIN_ROW, Sudoku::COLUMN_SIZE),
        std::out_of_range);
}

TEST(SudokuIndexTest, constructor_invalid_on_too_low_row)
{
    EXPECT_THROW(
        Sudoku::Index index(Sudoku::MIN_ROW - 1, Sudoku::MIN_COLUMN),
        std::out_of_range);
}

TEST(SudokuIndexTest, constructor_invalid_on_too_low_column)
{
    EXPECT_THROW(
        Sudoku::Index index(Sudoku::MIN_ROW, Sudoku::MIN_COLUMN - 1),
        std::out_of_range);
}

// Test Method: get_block_indices
TEST(SudokuIndexTest, get_indices_of_block_has_correct_number_of_elements)
{
    Sudoku::Index index(1, 2);
    Sudoku::IndexList indices_without_self = index.get_block_indices();
    EXPECT_EQ(indices_without_self.size(), 8);
    Sudoku::IndexList indices_with_self = index.get_block_indices(true);
    EXPECT_EQ(indices_with_self.size(), 9);
}
