# pragma once

#include "SudokuEntry.hpp"
#include "Definitions.hpp"
#include "SudokuIndex.hpp"
#include <cstdint>
#include <stdexcept>
#include <list>


namespace Sudoku
{

    /**
     * @brief A class representing all entries of a Sudoku puzzle.
     */
    class Data
    {
    public:
        Data ( void );
        Data ( const ValueArray& values 
        );
        std::uint_fast8_t value ( 
            std::uint_fast8_t row, 
            std::uint_fast8_t column 
        ) const;
        PossibleValuesList possible_values ( 
            std::uint_fast8_t row, 
            std::uint_fast8_t column 
        ) const;
        bool is_determined ( 
            std::uint_fast8_t row, 
            std::uint_fast8_t column 
        ) const;
        bool is_possible_value ( 
            std::uint_fast8_t row, 
            std::uint_fast8_t column,
            std::uint_fast8_t value 
        ) const;
        void set_value (
            std::uint_fast8_t row, 
            std::uint_fast8_t column,
            std::uint_fast8_t value 
        );
        void remove_possible_value (
            std::uint_fast8_t row, 
            std::uint_fast8_t column,
            std::uint_fast8_t value 
        );

    private:
        SudokuEntry entries[9][9] = {};
        bool is_in_index_range ( 
            std::uint_fast8_t row, 
            std::uint_fast8_t column 
        ) const;
    };  
}; // namespace Sudoku