#include <iostream>
#include <string>
#include "Point.h"
#include "Player.h"
#include "Map.h"
#include "Functions.h"
#include "SDL_F.h"

int main(int argc, char* args[])
{
    func::OSTest();
    console::ResetConsoleColor();

	if (!SDL::init())
        printf("Failed to initialize SDL\n");
    else
	{
        SDL_Delay( 2000 );
	}

    SDL::close();

    Map map{Map()};
    map.CreateMapFromFile(func::GetFile("maps/testMap.txt"));
    std::cout << map.Size() << std::endl;

    while (!map.PlayerTurn())
    {
    }

    std::cin.get();

    return 0;
}
