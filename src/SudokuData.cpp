#include "SudokuData.hpp"
#include "Definitions.hpp"

#include <cstdint>
#include <stdexcept>
#include <array>
#include <list>

// //////////////// Constructors ////////////////
SudokuData::SudokuData ( void )
{
    return;
}

SudokuData::SudokuData ( const Sudoku::ValueArray& values )
{
    for (std::uint_fast8_t row = 0; row < Sudoku::ROW_SIZE; ++row)
    {
        for (std::uint_fast8_t col = 0; col < Sudoku::COLUMN_SIZE; ++col)
        {       
            std::uint_fast8_t value = values[row * 9 + col];
            if (value != Sudoku::VALUE_UNDETERMINED)
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

std::list<std::uint_fast8_t> SudokuData::possible_values ( 
    std::uint_fast8_t row, 
    std::uint_fast8_t column 
) const
{

    if ( not is_in_index_range(row, column) )
    {
        throw std::out_of_range("Value out of range");
    }
    std::list<std::uint_fast8_t> possibilities;
    for ( std::uint_fast8_t value = Sudoku::MIN_VALUE; 
        value <= Sudoku::MAX_VALUE; 
        ++value )
    {
        if ( entries[row][column].is_possible_value(value) )
        {
            possibilities.push_back(value);
        }
    }
    return possibilities;
}

bool SudokuData::is_determined ( 
    std::uint_fast8_t row, 
    std::uint_fast8_t column 
) const
{   
    if ( not is_in_index_range(row, column) )
    {
        throw std::out_of_range("Value out of range");
    }
    return entries[row][column].is_determined();
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

void SudokuData::remove_possible_value (
    std::uint_fast8_t row, 
    std::uint_fast8_t column,
    std::uint_fast8_t value 
)
{
    if ( not is_in_index_range(row, column) )
    {
        throw std::out_of_range("Value out of range");
    }
    entries[row][column].remove_possible_value(value);
    return;
}

// //////////////// Private methods ////////////////
bool SudokuData::is_in_index_range ( std::uint_fast8_t row, std::uint_fast8_t column ) const
{
    const bool row_in_range = ( 0 <= row &&  Sudoku::ROW_SIZE > row );
    const bool column_in_range = ( 0 <= column &&  Sudoku::COLUMN_SIZE > column );
    return row_in_range && column_in_range;
}