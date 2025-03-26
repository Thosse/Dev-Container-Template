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
                set_value(row, col, value);
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

bool SudokuData::is_possible_value ( 
    std::uint_fast8_t row, 
    std::uint_fast8_t column,
    std::uint_fast8_t value 
) const
{
    if ( not is_in_index_range(row, column) )
    {
        throw std::out_of_range("Value out of range");
    }
    return entries[row][column].is_possible_value(value);
}

void SudokuData::set_value (
    std::uint_fast8_t row, 
    std::uint_fast8_t column,
    std::uint_fast8_t value 
)
{   
    if ( not is_in_index_range(row, column) )
    {
        throw std::out_of_range("Value out of range");
    }
    entries[row][column].set_value(value);
    return;
}

// //////////////// Private methods ////////////////
bool SudokuData::is_in_index_range ( std::uint_fast8_t row, std::uint_fast8_t column ) const
{
    return row >= 0 && row < ROW_SIZE && column >= 0 && column < COLUMN_SIZE;
}