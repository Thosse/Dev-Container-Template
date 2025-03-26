#include <span>
#include <cstdint>
#include <list>
#include <stdexcept>

/**
 * @brief A class representing a single element of a Sudoku puzzle.
 */
class SudokuElement
{
    public:
        constexpr static std::uint_fast16_t VALUE_UNDETERMINED = 0;
        constexpr static std::uint_fast16_t ALL_VALUES_POSSIBLE = 0b1111111110;
        constexpr static std::uint_fast8_t MIN_VALUE = 1;
        constexpr static std::uint_fast8_t MAX_VALUE = 9;

        SudokuElement ( void );
        SudokuElement ( std::uint_fast8_t value );
        bool is_determined ( void ) const;
        bool is_possible_value ( std::uint_fast8_t value ) const;
        std::uint_fast8_t value ( void ) const;
        void set_value ( std::uint_fast8_t value );
        void remove_possible_value ( std::uint_fast8_t value );

    private:
    std::uint_fast16_t data = ALL_VALUES_POSSIBLE;

        inline std::uint_fast16_t bitmask( std::uint_fast8_t value ) const;
        inline bool is_in_value_range ( std::uint_fast8_t value ) const;
};
