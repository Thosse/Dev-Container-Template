# pragma once

#include "Definitions.hpp"
#include <cstdint>
#include <stdexcept>

/**
 * @brief A class representing a single element of a Sudoku puzzle.
 */
class SudokuEntry
{
    public:
        SudokuEntry ( void );
        SudokuEntry ( std::uint_fast8_t value );
        bool is_determined ( void ) const;
        bool is_possible_value ( std::uint_fast8_t value ) const;
        std::uint_fast8_t value ( void ) const;
        void set_value ( std::uint_fast8_t value );
        void remove_possible_value ( std::uint_fast8_t value );

    private:
        typedef std::uint_fast16_t PossibleValues;
        // staticassert(MAX_VALUE < sizeof(PossibleValues) * 8 - 1, 
        //     "Too many possible values for the data type");
        static constexpr PossibleValues ALL_VALUES_POSSIBLE = 0b1111111110;
        
        PossibleValues data = ALL_VALUES_POSSIBLE;

        inline PossibleValues bitmask( std::uint_fast8_t value ) const;
        inline bool is_in_value_range ( std::uint_fast8_t value ) const;
};
