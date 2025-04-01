#include "SudokuData.hpp"
#include "Definitions.hpp"

#include <cstdint>
#include <stdexcept>
#include <array>
#include <list>

namespace Sudoku
{
    // //////////////// Constructors ////////////////
    Data::Data ( void )
    {
        return;
    }

    Data::Data ( const ValueArray& values )
    {
        for (std::uint_fast8_t row = 0; row < ROW_SIZE; ++row)
        {
            for (std::uint_fast8_t col = 0; col < COLUMN_SIZE; ++col)
            {       
                std::uint_fast8_t value = values[row * 9 + col];
                if (value != VALUE_UNDETERMINED)
                {
                    set_value(row, col, value);
                }
            }
        }
        return;
    }

    // //////////////// Public methods ////////////////
    std::uint_fast8_t Data::value ( 
        std::uint_fast8_t row, 
        std::uint_fast8_t column  ) const
    {
        return entries[row][column].value();
    }

    PossibleValuesList Data::possible_values ( 
        std::uint_fast8_t row, 
        std::uint_fast8_t column ) const
    {

        if ( not is_in_index_range(row, column) )
        {
            throw std::out_of_range("Value out of range");
        }
        PossibleValuesList possibilities;
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

    bool Data::is_determined ( 
        std::uint_fast8_t row, 
        std::uint_fast8_t column ) const
    {   
        if ( not is_in_index_range(row, column) )
        {
            throw std::out_of_range("Value out of range");
        }
        return entries[row][column].is_determined();
    }

    bool Data::is_possible_value ( 
        std::uint_fast8_t row, 
        std::uint_fast8_t column,
        std::uint_fast8_t value ) const
    {
        if ( not is_in_index_range(row, column) )
        {
            throw std::out_of_range("Value out of range");
        }
        return entries[row][column].is_possible_value(value);
    }

    void Data::set_value (
        std::uint_fast8_t row, 
        std::uint_fast8_t column,
        std::uint_fast8_t value )
    {   
        if ( not is_in_index_range(row, column) )
        {
            throw std::out_of_range("Value out of range");
        }
        entries[row][column].set_value(value);
        return;
    }

    void Data::remove_possible_value (
        std::uint_fast8_t row, 
        std::uint_fast8_t column,
        std::uint_fast8_t value )
    {
        if ( not is_in_index_range(row, column) )
        {
            throw std::out_of_range("Value out of range");
        }
        entries[row][column].remove_possible_value(value);
        return;
    }

    // //////////////// Private methods ////////////////
    bool Data::is_in_index_range ( std::uint_fast8_t row, std::uint_fast8_t column ) const
    {
        const bool row_in_range = ( 0 <= row && ROW_SIZE > row );
        const bool column_in_range = ( 0 <= column && COLUMN_SIZE > column );
        return row_in_range && column_in_range;
    }

};