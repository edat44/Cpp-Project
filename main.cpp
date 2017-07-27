#include <iostream>
#include <string>
#include "Point.h"
#include "Player.h"
#include "Map.h"

int main()
{
    
    Map map{Map()};
    std::cout << map.Size() << std::endl;
    map.CreateBlankMap(Point(40, 10));
    
    
    while (!map.PlayerTurn())
    {
    }
    
    std::cin.get();
    return 0;
}