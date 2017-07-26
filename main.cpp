#include <iostream>
#include <string>
#include "Point.h"
#include "Player.h"

int main()
{
    Player playah = Player("Edward");
    std::cout << playah << std::endl;
    
    while (!playah.Move())
    {
        std::cout << playah << std::endl;
    }
    
    std::cin.get();
    return 0;
}