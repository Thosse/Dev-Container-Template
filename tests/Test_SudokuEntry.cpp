#include <gtest/gtest.h>
#include "SudokuEntry.hpp"

TEST(SudokuEntryTest, DefaultConstructor) {
    SudokuEntry element;
    EXPECT_EQ(element.value(), 0);
    EXPECT_FALSE(element.is_determined());
}

TEST(SudokuEntryTest, ParameterizedConstructor) {
    SudokuEntry element(5);
    EXPECT_EQ(element.value(), 5);
    EXPECT_TRUE(element.is_determined());
}

TEST(SudokuEntryTest, set_value) {
    SudokuEntry element;
    element.set_value(7);
    EXPECT_EQ(element.value(), 7);
    EXPECT_TRUE(element.is_determined());
}

TEST(SudokuEntryTest, set_too_high_value) {
    SudokuEntry element;
    EXPECT_THROW(
        element.set_value(Sudoku::MAX_VALUE + 1), 
        std::out_of_range);
}

TEST(SudokuEntryTest, set_too_low_value) {
    SudokuEntry element;
    EXPECT_THROW(
        element.set_value(Sudoku::MIN_VALUE - 1), 
        std::out_of_range);
}

TEST(SudokuEntryTest, set_bool_as_value) {
    SudokuEntry element;
    element.set_value(true);
    EXPECT_TRUE(element.is_determined());
    EXPECT_EQ(element.value(), 1);
}

TEST(SudokuEntryTest, remove_possible_value) {
    SudokuEntry element;
    element.remove_possible_value(5);
    EXPECT_FALSE(element.is_possible_value(5));
}

TEST(SudokuEntryTest, remove_too_high_possible_value) {
    SudokuEntry element;
    EXPECT_THROW(
        element.remove_possible_value(Sudoku::MAX_VALUE + 1), 
        std::out_of_range);
}

TEST(SudokuEntryTest, remove_too_low_possible_value) {
    SudokuEntry element;
    EXPECT_THROW(
        element.remove_possible_value(Sudoku::MIN_VALUE - 1), 
        std::out_of_range);
}