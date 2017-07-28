#include <iostream>
#include <string>
#include "Point.h"
#include "Player.h"
#include "Map.h"
#include "Functions.h"

int main()
{
    console::SetConsoleColor(console::WINDOWS_RED | console::WINDOWS_INTENSITY, console::WINDOWS_BLUE);
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