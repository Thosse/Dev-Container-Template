#include "SudokuEntry.hpp"
#include "SudokuData.hpp"

#include "gtest/gtest.h"
#include <cstdint>
#include <stdexcept>

// // //////////////// Test data ////////////////
// struct TestData_SudokuData {
//     Sudoku::ValueArray values;
// };

Sudoku::ValueArray values_first_row_almost_set = {
    1,2,3,4,5,6,7,8,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0   
};

Sudoku::ValueArray values_first_column_almost_set = {
    1,0,0,0,0,0,0,0,0,
    2,0,0,0,0,0,0,0,0,
    3,0,0,0,0,0,0,0,0,
    4,0,0,0,0,0,0,0,0,
    5,0,0,0,0,0,0,0,0,
    6,0,0,0,0,0,0,0,0,
    7,0,0,0,0,0,0,0,0,
    8,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0   
};

Sudoku::ValueArray values_first_block_almost_set = {
    1,2,3,0,0,0,0,0,0,
    4,0,6,0,0,0,0,0,0,
    7,8,9,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0   
};



// Test Constructors
TEST(SudokuDataTest, DefaultConstructor) {
    SudokuData data;
    for (std::uint_fast8_t row = 0; row < Sudoku::ROW_SIZE; ++row)
    {
        for (std::uint_fast8_t col = 0; col < Sudoku::COLUMN_SIZE; ++col)
        {
            EXPECT_EQ(data.value(row, col), Sudoku::VALUE_UNDETERMINED);
        }
    }
}

TEST(SudokuDataTest, ParameterizedConstructor_row_almost_set) {
    SudokuData data(values_first_row_almost_set);
    const std::uint_fast8_t row = 0;
    for (std::uint_fast8_t col = 0; col < Sudoku::COLUMN_SIZE; ++col)
    {
        EXPECT_EQ(
            data.value(row, col), 
            values_first_row_almost_set[col]);
    }
}

TEST(SudokuDataTest, ParameterizedConstructor_column_almost_set) {
    SudokuData data(values_first_column_almost_set);
    const std::uint_fast8_t col = 0;
    for (std::uint_fast8_t row = 0; row < Sudoku::ROW_SIZE; ++row)
    {
        EXPECT_EQ(
            data.value(row, col), 
            values_first_column_almost_set[Sudoku::ROW_SIZE * row]);
    }
}

// Test Method: is_determined
TEST(SudokuDataTest, is_not_determined_on_empty_data) {
    SudokuData data;
    for (std::uint_fast8_t row = 0; row < Sudoku::ROW_SIZE; ++row)
    {
        for (std::uint_fast8_t col = 0; col < Sudoku::COLUMN_SIZE; ++col)
        {
            EXPECT_FALSE(data.is_determined(row, col));
        }
    }
}

TEST(SudokuDataTest, is_determined_after_set_data) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 7;
    data.set_value(row, col, value);
    EXPECT_EQ(data.is_determined(row, col), col < Sudoku::COLUMN_SIZE - 1);
}

// Test Method: is_possible_value
TEST(SudokuDataTest, all_values_possible_on_empty_data) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    for (std::uint_fast8_t possible = 1; possible <= Sudoku::MAX_VALUE; ++possible)
    {
        EXPECT_TRUE(data.is_possible_value(row, col, possible));
    }
};


TEST(SudokuDataTest, only_one_possible_value_after_set_value) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 7;
    data.set_value(row, col, value);
    for (std::uint_fast8_t possible = 1; possible <= Sudoku::MAX_VALUE; ++possible)
    {
        if (possible != value)
        {
            EXPECT_FALSE(data.is_possible_value(row, col, possible));
        }
    }
    EXPECT_TRUE(data.is_possible_value(row, col, value));
}

TEST(SudokuDataTest, is_possible_value_on_out_of_row_range) {
    SudokuData data;
    const std::uint_fast8_t row = Sudoku::ROW_SIZE;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.is_possible_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, is_possible_value_on_out_of_column_range) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = Sudoku::COLUMN_SIZE;
    const std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.is_possible_value(row, col, value), 
        std::out_of_range);
}

// Test Method: set_value
TEST(SudokuDataTest, set_value) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 5;
    data.set_value(row, col, value);
    EXPECT_EQ(data.value(row, col), value);
}

TEST(SudokuDataTest, set_too_high_value) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = Sudoku::MAX_VALUE + 1;
    EXPECT_THROW(
        data.set_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, set_too_low_value) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = Sudoku::MIN_VALUE - 1;
    EXPECT_THROW(
        data.set_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, set_value_out_of_row_range) {
    SudokuData data;
    const std::uint_fast8_t row = Sudoku::ROW_SIZE;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.set_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, set_value_out_of_column_range) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = Sudoku::COLUMN_SIZE;
    const std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.set_value(row, col, value), 
        std::out_of_range);
}
TEST(SudokuDataTest, set_value_does_not_affect_other_values) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 5;
    data.set_value(row, col, value);
    for (std::uint_fast8_t r = 0; r < Sudoku::ROW_SIZE; ++r)
    {
        for (std::uint_fast8_t c = 0; c < Sudoku::COLUMN_SIZE; ++c)
        {
            if (r != row || c != col)
            {
                EXPECT_EQ( data.value(r, c), Sudoku::VALUE_UNDETERMINED);
            }
            else
            {
                EXPECT_EQ( data.value(r, c), value);
            }
        }
    }
}

// Test Method: remove_possible_value
TEST(SudokuDataTest, remove_possible_value) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 5;
    data.remove_possible_value(row, col, value);
    EXPECT_FALSE(data.is_possible_value(row, col, value));
}

TEST(SudokuDataTest, remove_too_high_possible_value) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = Sudoku::MAX_VALUE + 1;
    EXPECT_THROW(
        data.remove_possible_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, remove_too_low_possible_value) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = Sudoku::MIN_VALUE - 1;
    EXPECT_THROW(
        data.remove_possible_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, remove_possible_value_out_of_row_range) {
    SudokuData data;
    const std::uint_fast8_t row = Sudoku::ROW_SIZE;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.remove_possible_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, remove_possible_value_out_of_column_range) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = Sudoku::COLUMN_SIZE;
    const std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.remove_possible_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, remove_value_does_not_affect_other_values )
{
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 5;
    data.remove_possible_value(row, col, value);
    for (std::uint_fast8_t possible = Sudoku::MIN_VALUE; 
        possible <= Sudoku::MAX_VALUE; 
        ++possible)
    {
        if (possible != value)
        {
            EXPECT_TRUE(data.is_possible_value(row, col, possible));
        }
    }
}

TEST(SudokuDataTest, remove_value_does_not_affect_other_entries) {
    SudokuData data;
    const std::uint_fast8_t row = 3;
    const std::uint_fast8_t col = 7;
    const std::uint_fast8_t value = 5;
    data.remove_possible_value(row, col, value);
    for (std::uint_fast8_t r = 0; r < Sudoku::ROW_SIZE; ++r)
    {
        for (std::uint_fast8_t c = 0; c < Sudoku::COLUMN_SIZE; ++c)
        {
            if (r != row || c != col)
            {
                EXPECT_TRUE(data.is_possible_value(r, c, value));
            }
        }
    }
}

