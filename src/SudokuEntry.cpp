#include "SudokuEntry.hpp"

#include <cstdint>
#include <stdexcept>


// //////////////// Constructors ////////////////
SudokuEntry::SudokuEntry ( void )
{
    data = ALL_VALUES_POSSIBLE;
}


SudokuEntry::SudokuEntry ( std::uint_fast8_t value )
{
    set_value(value);
    return;
}


// //////////////// Public methods ////////////////
bool SudokuEntry::is_determined ( void ) const
{
    return __builtin_popcount(data) == 1;
}


bool SudokuEntry::is_possible_value ( std::uint_fast8_t value ) const
{
    if (not is_in_value_range(value))
    {
        throw std::out_of_range("Value out of range");
    }
    return data & bitmask(value);
}


std::uint_fast8_t SudokuEntry::value ( void ) const
{
    if ( is_determined() )
    {
        for (std::uint_fast8_t i = Sudoku::MIN_VALUE; 
            i <= Sudoku::MAX_VALUE; 
            ++i)
        {
            if (data & bitmask(i))
            {
                return i;
            }
        }
    }
    return Sudoku::VALUE_UNDETERMINED;
}


void SudokuEntry::set_value ( std::uint_fast8_t value )
{
    if (not is_possible_value(value))
    {
        throw std::out_of_range("Value not possible");
    }
    data = bitmask(value);
    return;
}

void SudokuEntry::remove_possible_value ( std::uint_fast8_t value )
{
    if (not is_in_value_range(value))
    {
        throw std::out_of_range("Value out of range");
    }
    data &= ~bitmask(value);
    return;
}


// //////////////// Private methods ////////////////
std::uint_fast16_t SudokuEntry::bitmask( std::uint_fast8_t value ) const
{
    if (not is_in_value_range(value))
    {
        throw std::out_of_range("Value out of range");
    }
    return 1 << value;
}


inline bool SudokuEntry::is_in_value_range ( std::uint_fast8_t value ) const
{
    return Sudoku::MIN_VALUE <= value && value <= Sudoku::MAX_VALUE;
}





