#include <gtest/gtest.h>
#include "SudokuElement.hpp"

TEST(SudokuElementTest, DefaultConstructor) {
    SudokuElement element;
    EXPECT_EQ(element.value(), 0);
    EXPECT_FALSE(element.is_determined());
}

TEST(SudokuElementTest, ParameterizedConstructor) {
    SudokuElement element(5);
    EXPECT_EQ(element.value(), 5);
    EXPECT_TRUE(element.is_determined());
}

TEST(SudokuElementTest, set_value) {
    SudokuElement element;
    element.set_value(7);
    EXPECT_EQ(element.value(), 7);
    EXPECT_TRUE(element.is_determined());
}

TEST(SudokuElementTest, set_too_high_value) {
    SudokuElement element;
    EXPECT_THROW(
        element.set_value(SudokuElement::MAX_VALUE + 1), 
        std::out_of_range);
}

TEST(SudokuElementTest, set_too_low_value) {
    SudokuElement element;
    EXPECT_THROW(
        element.set_value(SudokuElement::MIN_VALUE - 1), 
        std::out_of_range);
}

TEST(SudokuElementTest, set_bool_as_value) {
    SudokuElement element;
    element.set_value(true);
    EXPECT_TRUE(element.is_determined());
    EXPECT_EQ(element.value(), 1);
}

TEST(SudokuElementTest, remove_possible_value) {
    SudokuElement element;
    element.remove_possible_value(5);
    EXPECT_FALSE(element.is_possible_value(5));
}

TEST(SudokuElementTest, remove_too_high_possible_value) {
    SudokuElement element;
    EXPECT_THROW(
        element.remove_possible_value(SudokuElement::MAX_VALUE + 1), 
        std::out_of_range);
}

TEST(SudokuElementTest, remove_too_low_possible_value) {
    SudokuElement element;
    EXPECT_THROW(
        element.remove_possible_value(SudokuElement::MIN_VALUE - 1), 
        std::out_of_range);
}