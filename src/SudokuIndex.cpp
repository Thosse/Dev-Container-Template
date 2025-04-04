#include "SudokuIndex.hpp"
#include "Definitions.hpp"
#include <cstdint>
#include <list>
#include <stdexcept>

namespace Sudoku
{


    Index::Index ( std::uint_fast8_t row, std::uint_fast8_t column )
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

    IndexList Index::get_block_indices( bool include_self ) const
    {
        IndexList indices;
        const std::uint_fast8_t block_size = 3;
        const std::uint_fast8_t block_row_min = row / block_size;
        const std::uint_fast8_t block_row_max = block_row_min + block_size;
        const std::uint_fast8_t block_column_min = column / block_size;
        const std::uint_fast8_t block_column_max = block_column_min + block_size;

        for (std::uint_fast8_t r = block_column_min; r < block_row_max; ++r)
        {
            for (std::uint_fast8_t c = block_column_min; c < block_column_max; ++c)
            {
                if ( include_self || (row != r) || (column != c) )
                {
                    indices.push_back( Index(r, c) );
                }
            }
        }
        return indices;
    };

    bool Index::operator==( const Index& other ) const
    {
        return (row == other.row && column == other.column);
    };

    bool Index::operator<( const Index& other ) const
    {
        if (row < other.row)
        {
            return true;
        }
        else if (row == other.row)
        {
            return column < other.column;
        }
        return false;
    };

    bool Index::operator>( const Index& other ) const
    {
        if (row > other.row)
        {
            return true;
        }
        else if (row == other.row)
        {
            return column > other.column;
        }
        return false;
    };
};