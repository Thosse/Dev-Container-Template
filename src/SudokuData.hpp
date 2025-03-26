# pragma once

#include "SudokuEntry.hpp"

#include <cstdint>
#include <stdexcept>
#include <array>


/**
 * @brief A class representing all entries of a Sudoku puzzle.
 */
class SudokuData
{
    public:
        static constexpr std::uint_fast8_t ROW_SIZE = 9;
        static constexpr std::uint_fast8_t COLUMN_SIZE = 9;
        static constexpr std::uint_fast8_t NUMBER_OF_ELEMENTS 
            = ROW_SIZE * COLUMN_SIZE;

        typedef std::array<std::uint_fast8_t, SudokuData::NUMBER_OF_ELEMENTS> 
            ValueArray;

        SudokuData ( void );
        SudokuData ( 
            const ValueArray& values 
        );
        std::uint_fast8_t value ( 
            std::uint_fast8_t row, 
            std::uint_fast8_t column 
        ) const;

    private:
        SudokuEntry entries[9][9] = {};
        // bool is_in_index_range ( std::uint_fast8_t index ) const;

};