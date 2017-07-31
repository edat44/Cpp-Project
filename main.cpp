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

        std::shared_ptr<Map> map;

        if( !loadMedia(map) )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }

                    //Handle input for the dot
                    map->handleEvent( e );
                }

                //Move the dot
                map->Move();
                map->SetCamera();

                //Clear screen
                SDL_SetRenderDrawColor(SDL::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( SDL::gRenderer );

                //Render dot
                map->Render();

                //Update screen
                SDL_RenderPresent( SDL::gRenderer );
            }
        }
	}
    while (!map.PlayerTurn())
    {
    }

    SDL::close(map);

    return 0;
}
