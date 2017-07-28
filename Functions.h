#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdint>
#include <iostream>

#define WINDOWS 1
#define OSX 2

#if defined(_WIN32) || defined(_WIN64)
    #include <Windows.h>
    #define PLATFORM_NAME WINDOWS
    using color_t = uint8_t;
#elif defined(__APPLE__) || defined(__MACH__)
    #define PLATFORM_NAME OSX
    using color_t = uint8_t; //CHANGE
#else
    #define PLATFORM_NAME NULL
    using color_t = NULL;
#endif


namespace func
{
    bool OSTest();
}


namespace console
{
    extern color_t COLOR_RED;
    extern color_t COLOR_BLUE;
    extern color_t COLOR_GREEN;
    extern color_t COLOR_INTENSITY;
    
    extern color_t COLOR_WHITE;
    extern color_t COLOR_BLACK;
    extern color_t COLOR_YELLOW;
    extern color_t COLOR_PURPLE;
    extern color_t COLOR_CYAN;

    
    int SetConsoleColor(color_t foreground, color_t background, bool debug = false);
    int ResetConsoleColor(bool debug = false);
}

#endif