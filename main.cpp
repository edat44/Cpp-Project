#include <iostream>
#include <string>
#include "Point.h"
#include "Player.h"
#include "Map.h"
#include "Functions.h"

int main()
{
    func::OSTest();
    console::ResetConsoleColor();
    Map map{Map()};
    map.CreateMapFromFile("testMap.txt");
    std::cout << map.Size() << std::endl;

    while (!map.PlayerTurn())
    {
    }

    std::cin.get();
    return 0;
}
