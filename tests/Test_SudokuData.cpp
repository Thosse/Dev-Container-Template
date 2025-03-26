#include "SudokuEntry.hpp"
#include "SudokuData.hpp"

#include "gtest/gtest.h"
#include <cstdint>
#include <stdexcept>

// // //////////////// Test data ////////////////
struct TestData_SudokuData {
    SudokuData::ValueArray values;
};

SudokuData::ValueArray values_first_row_almost_set = {
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

SudokuData::ValueArray values_first_column_almost_set = {
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

SudokuData::ValueArray values_first_block_almost_set = {
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
    for (std::uint_fast8_t row = 0; row < SudokuData::ROW_SIZE; ++row)
    {
        for (std::uint_fast8_t col = 0; col < SudokuData::COLUMN_SIZE; ++col)
        {
            EXPECT_EQ(data.value(row, col), SudokuEntry::VALUE_UNDETERMINED);
        }
    }
}

TEST(SudokuDataTest, ParameterizedConstructor_row_almost_set) {
    SudokuData data(values_first_row_almost_set);
    std::uint_fast8_t row = 0;
    for (std::uint_fast8_t col = 0; col < SudokuData::COLUMN_SIZE; ++col)
    {
        EXPECT_EQ(
            data.value(row, col), 
            values_first_row_almost_set[col]);
    }
}

TEST(SudokuDataTest, ParameterizedConstructor_column_almost_set) {
    SudokuData data(values_first_column_almost_set);
    std::uint_fast8_t col = 0;
    for (std::uint_fast8_t row = 0; row < SudokuData::ROW_SIZE; ++row)
    {
        EXPECT_EQ(
            data.value(row, col), 
            values_first_column_almost_set[SudokuData::ROW_SIZE * row]);
    }
}

// Test Method: is_possible_value
TEST(SudokuDataTest, all_values_possible_on_empty_data) {
    SudokuData data;
    std::uint_fast8_t row = 3;
    std::uint_fast8_t col = 7;
    for (std::uint_fast8_t possible = 1; possible <= SudokuEntry::MAX_VALUE; ++possible)
    {
        EXPECT_TRUE(data.is_possible_value(row, col, possible));
    }
};


TEST(SudokuDataTest, only_one_possible_value_after_set_value) {
    SudokuData data;
    std::uint_fast8_t row = 3;
    std::uint_fast8_t col = 7;
    std::uint_fast8_t value = 7;
    data.set_value(row, col, value);
    for (std::uint_fast8_t possible = 1; possible <= SudokuEntry::MAX_VALUE; ++possible)
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
    std::uint_fast8_t row = SudokuData::ROW_SIZE;
    std::uint_fast8_t col = 7;
    std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.is_possible_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, is_possible_value_on_out_of_column_range) {
    SudokuData data;
    std::uint_fast8_t row = 3;
    std::uint_fast8_t col = SudokuData::COLUMN_SIZE;
    std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.is_possible_value(row, col, value), 
        std::out_of_range);
}

// Test Method: set_value
TEST(SudokuDataTest, set_value) {
    SudokuData data;
    std::uint_fast8_t row = 3;
    std::uint_fast8_t col = 7;
    std::uint_fast8_t value = 5;
    data.set_value(row, col, value);
    EXPECT_EQ(data.value(row, col), value);
}

TEST(SudokuDataTest, set_too_high_value) {
    SudokuData data;
    std::uint_fast8_t row = 3;
    std::uint_fast8_t col = 7;
    std::uint_fast8_t value = SudokuEntry::MAX_VALUE + 1;
    EXPECT_THROW(
        data.set_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, set_too_low_value) {
    SudokuData data;
    std::uint_fast8_t row = 3;
    std::uint_fast8_t col = 7;
    std::uint_fast8_t value = SudokuEntry::MIN_VALUE - 1;
    EXPECT_THROW(
        data.set_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, set_value_out_of_row_range) {
    SudokuData data;
    std::uint_fast8_t row = SudokuData::ROW_SIZE;
    std::uint_fast8_t col = 7;
    std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.set_value(row, col, value), 
        std::out_of_range);
}

TEST(SudokuDataTest, set_value_out_of_column_range) {
    SudokuData data;
    std::uint_fast8_t row = 3;
    std::uint_fast8_t col = SudokuData::COLUMN_SIZE;
    std::uint_fast8_t value = 5;
    EXPECT_THROW(
        data.set_value(row, col, value), 
        std::out_of_range);
}