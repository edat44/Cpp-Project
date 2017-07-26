#include <iostream>
#include <string>
#include "Point.h"


int main()
{
    Point me;
    me += Point(5, -5);
    std::cout << me << std::endl;
    
    char shift;
    while (shift != 'x')
    {
        std::cout << "Move using wasd, or 'x' to exit: ";
        std::cin >> shift;
        me.Shift(shift);
        std::cout << me << std::endl;
    }
    
    std::cin.get();
    return 0;
}