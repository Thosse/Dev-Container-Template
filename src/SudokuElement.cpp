#include <span>
#include <cstdint>
#include <list>
#include <stdexcept>
#include "SudokuElement.hpp"


// //////////////// Constructors ////////////////
SudokuElement::SudokuElement ( void )
{
    data = ALL_VALUES_POSSIBLE;
}


SudokuElement::SudokuElement ( std::uint_fast8_t value )
{
    set_value(value);
    return;
}


// //////////////// Public methods ////////////////
bool SudokuElement::is_determined ( void ) const
{
    return __builtin_popcount(data) == 1;
}


bool SudokuElement::is_possible_value ( std::uint_fast8_t value ) const
{
    if (not is_in_value_range(value))
    {
        throw std::out_of_range("Value out of range");
    }
    return data & bitmask(value);
}


std::uint_fast8_t SudokuElement::value ( void ) const
{
    if (is_determined())
    {
        for (std::uint_fast8_t i = MIN_VALUE; i <= MAX_VALUE; ++i)
        {
            if (data & bitmask(i))
            {
                return i;
            }
        }
    }
    return VALUE_UNDETERMINED;
}


void SudokuElement::set_value ( std::uint_fast8_t value )
{
    if (not is_possible_value(value))
    {
        throw std::out_of_range("Value not possible");
    }
    data = bitmask(value);
    return;
}

void SudokuElement::remove_possible_value ( std::uint_fast8_t value )
{
    if (not is_in_value_range(value))
    {
        throw std::out_of_range("Value out of range");
    }
    data &= ~bitmask(value);
    return;
}


// //////////////// Private methods ////////////////
std::uint_fast16_t SudokuElement::bitmask( std::uint_fast8_t value ) const
{
    if (not is_in_value_range(value))
    {
        throw std::out_of_range("Value out of range");
    }
    return 1 << value;
}


inline bool SudokuElement::is_in_value_range ( std::uint_fast8_t value ) const
{
    return MIN_VALUE <= value && value <= MAX_VALUE;
}





