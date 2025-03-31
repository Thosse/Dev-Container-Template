#pragma once

#include "Definitions.hpp"
#include <cstdint>
#include <list>
#include <stdexcept>

namespace Sudoku
{

    struct Index 
    {
    public:
        const std::uint_fast8_t row;
        const std::uint_fast8_t column;

        Index ( std::uint_fast8_t row, std::uint_fast8_t column )
            : row(row), column(column) 
        {
            bool row_out_of_range = ( MIN_ROW > row || MAX_ROW < row );
            bool column_out_of_range = ( MIN_COLUMN > column || MAX_COLUMN < column );
            if ( row_out_of_range || column_out_of_range )
            {
                throw std::out_of_range("Index out of range");
            }
            return;
        };

        bool operator==( const Index& other ) const
        {
            return (row == other.row && column == other.column);
        }
    };

    typedef std::list<Index> IndexList;

}