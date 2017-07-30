//Using SDL and standard IO
#include "Functions.h"
#if PLATFORM_NAME == WINDOWS
    #include <SDL.h>
#elif PLATFORM_NAME == OSX
    #include <SDL2/SDL.h>
#endif
#include <stdio.h>

namespace SDL
{
    //The window we'll be rendering to
    extern SDL_Window* gWindow;

    //The surface contained by the window
    extern SDL_Surface* gScreenSurface;

    //The image we will load and show on the screen
    extern SDL_Surface* gHelloWorld;

    extern const int SCREEN_WIDTH;
    extern const int SCREEN_HEIGHT;

    //Starts up SDL and creates window
    bool init();

    //Loads media
    bool loadMedia();

    //Frees media and shuts down SDL
    void close();
}
