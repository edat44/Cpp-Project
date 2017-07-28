#include <iostream>
#include <string>
#include "Point.h"
#include "Player.h"
#include "Map.h"

int main()
{
    
    Map map{Map()};
    map.CreateBlankMap(Point(40, 10));
    std::cout << map.Size() << std::endl;

    while (!map.PlayerTurn())
    {
    }
    
    std::cin.get();
    return 0;
}