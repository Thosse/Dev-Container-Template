#include "SudokuElement.hpp"
#include <iostream>

int main()
{
    SudokuElement element;
    std::cout << "Element is determined: " << element.is_determined() << std::endl;
    std::cout << "Element value: " << element.value() << std::endl;
    std::cout << "Element is possible value 5: " << element.is_possible_value(5) << std::endl;
    element.set_value(5);   
    std::cout << "Element value: " << element.value() << std::endl;
    return 0;
}