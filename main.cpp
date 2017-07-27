#include <iostream>
#include <string>
#include "Point.h"
#include "Player.h"
#include "Map.h"

int main()
{
    Player playah = Player();
    std::cout << playah << std::endl;
    
    Map map{Map()};
    std::cout << map.Size() << std::endl;
    
    while (!playah.Move())
    {
        std::cout << playah << std::endl;
    }
    
    std::cin.get();
    return 0;
}