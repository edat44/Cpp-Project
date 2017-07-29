#include <iostream>
#include <string>
#include "Point.h"
#include "Player.h"
#include "Map.h"
#include "Functions.h"

int main()
{
    func::OSTest();
    Map map{Map()};
    map.CreateBlankMap(Point(40, 10));
    std::cout << map.Size() << std::endl;

    while (!map.PlayerTurn())
    {
    }

    std::cin.get();
    return 0;
}
