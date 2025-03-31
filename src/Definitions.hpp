#pragma once

#include <cstdint>
#include <array>

namespace Sudoku
{   
    // Size
    static constexpr std::uint_fast8_t ROW_SIZE = 9;
    static constexpr std::uint_fast8_t COLUMN_SIZE = ROW_SIZE;
    // staticassert(ROW_SIZE == COLUMN_SIZE, "Row and column size must be equal");
    
    static constexpr std::uint_fast8_t NUMBER_OF_ELEMENTS 
        = ROW_SIZE * COLUMN_SIZE;
    typedef std::array<std::uint_fast8_t, NUMBER_OF_ELEMENTS> 
        ValueArray;
    
    // Values
    static constexpr std::uint_fast8_t MIN_VALUE = 1;
    static constexpr std::uint_fast8_t MAX_VALUE = ROW_SIZE;

    static constexpr std::uint_fast8_t VALUE_UNDETERMINED = 0;

    // Indexing
    static constexpr std::uint_fast8_t MIN_ROW = 0;
    static constexpr std::uint_fast8_t MAX_ROW = ROW_SIZE - 1;
    static constexpr std::uint_fast8_t MIN_COLUMN = 0;
    static constexpr std::uint_fast8_t MAX_COLUMN = COLUMN_SIZE - 1;

}