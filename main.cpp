#include <iostream>
#include <string>
#include "Point.h"
#include "Player.h"
#include "Map.h"
#include "Functions.h"

int main()
{
    func::OSTest();
    console::SetConsoleColor(console::COLOR_RED | console::COLOR_INTENSITY, console::COLOR_BLUE, true);
    Map map{Map()};
    map.CreateBlankMap(Point(40, 10));
    std::cout << map.Size() << std::endl;
    console::ResetConsoleColor();

    while (!map.PlayerTurn())
    {
    }
    
    std::cin.get();
    return 0;
}