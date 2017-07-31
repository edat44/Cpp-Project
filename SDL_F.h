#ifndef SDL_F_H
#define SDL_F_H

//Using SDL and standard IO
#include "Functions.h"
#if PLATFORM_NAME == WINDOWS
    #include <SDL.h>
    //#include <SDL_image.h>
#elif PLATFORM_NAME == OSX
    #include <SDL2/SDL.h>
#endif
#include <stdio.h>
#include "Map.h"

namespace SDL
{
    //The window we'll be rendering to
    extern SDL_Window* gWindow;

    //The surface contained by the window
    extern SDL_Renderer* gRenderer;


    extern const int SCREEN_WIDTH;
    extern const int SCREEN_HEIGHT;

    //Starts up SDL and creates window
    bool init();

    //Loads media
    bool loadMedia(std::shared_ptr<Map> map);

    //Frees media and shuts down SDL
    void close(std::shared_ptr<Map> map);

    //Checks collision box against set of tiles
    bool touchesWall( SDL_Rect box, map_t tiles);

    //Box collision detector
    bool checkCollision(SDL_Rect a, SDL_Rect b);
}

#endif // SDL_F_H
