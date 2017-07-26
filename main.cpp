#include <iostream>
#include <string>
#include "Position.h"


int main()
{
    Position me(5, 10);
    std::cout << me.Print() << std::endl;
    std::cin.get();
    return 0;
}