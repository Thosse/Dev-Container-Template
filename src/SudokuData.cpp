#include "SudokuData.hpp"
#include "SudokuEntry.hpp"

#include <cstdint>
#include <stdexcept>
#include <array>

// //////////////// Constructors ////////////////
SudokuData::SudokuData ( void )
{
    return;
}

SudokuData::SudokuData ( const ValueArray& values )
{
    for (std::uint_fast8_t row = 0; row < ROW_SIZE; ++row)
    {
        for (std::uint_fast8_t col = 0; col < COLUMN_SIZE; ++col)
        {       
            std::uint_fast8_t value = values[row * 9 + col];
            if (value != SudokuEntry::VALUE_UNDETERMINED)
            {
                entries[row][col].set_value(values[row * 9 + col]);
            }
        }
    }
    return;
}

// //////////////// Public methods ////////////////
std::uint_fast8_t SudokuData::value ( 
    std::uint_fast8_t row, 
    std::uint_fast8_t column 
) const
{
    return entries[row][column].value();
}