#include <iostream>
#include <string>
#include "Point.h"


int main()
{
    Point pt;
    pt += Point(5, -5);
    std::cout << pt << std::endl;
    
    char shift;
    while (shift != 'x')
    {
        std::cout << "Move using wasd, or 'x' to exit: ";
        std::cin >> shift;
        pt.Shift(shift);
        std::cout << pt << std::endl;
    }
    
    std::cin.get();
    return 0;
}