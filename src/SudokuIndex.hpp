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

        Index ( std::uint_fast8_t row, std::uint_fast8_t column );

        std::list<Index> get_block_indices( bool include_self = false ) const;
        bool operator==( const Index& other ) const;
        bool operator<( const Index& other ) const;
        bool operator>( const Index& other ) const;
        
    };

    typedef std::list<Index> IndexList;

}