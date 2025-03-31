#include "SudokuEntry.hpp"
#include "Definitions.hpp"
#include <iostream>

int main()
{
    SudokuEntry entry;
    std::cout << "entry is determined: " << entry.is_determined() << std::endl;
    std::cout << "entry value: " << (int) entry.value() << std::endl;
    std::cout << "entry is possible value 5: " << entry.is_possible_value(5) << std::endl;
    std::cout << "setting value to 5..." << std::endl;
    entry.set_value(5);   
    std::cout << "entry value: " << (int) entry.value() << std::endl;
    std::cout << "entry is possible value 5: " << entry.is_possible_value(5) << std::endl;
    Sudoku::Index index = {1, 2};
    return 0;
}