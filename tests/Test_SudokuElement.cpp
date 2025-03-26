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

TEST(SudokuElementTest, SetValue) {
    SudokuElement element;
    element.set_value(7);
    EXPECT_EQ(element.value(), 7);
    EXPECT_TRUE(element.is_determined());
}

TEST(SudokuElementTest, SetFixed) {
    SudokuElement element;
    element.set_value(true);
    EXPECT_TRUE(element.is_determined());
}
