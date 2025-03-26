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



// // //////////////// Constructors ////////////////
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