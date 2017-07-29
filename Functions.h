#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdint>
#include <iostream>
#include <string>

#define WINDOWS 1
#define OSX 2

#if defined(_WIN32) || defined(_WIN64)
    #include <Windows.h>
    #define PLATFORM_NAME WINDOWS
    using color_t = uint8_t;
#elif defined(__APPLE__) || defined(__MACH__)
    #define PLATFORM_NAME OSX
    using color_t = uint8_t;
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
    extern color_t COLOR_BOLD;

    extern color_t COLOR_RED;
    extern color_t COLOR_BLUE;
    extern color_t COLOR_GREEN;
    extern color_t COLOR_WHITE;
    extern color_t COLOR_BLACK;
    extern color_t COLOR_YELLOW;
    extern color_t COLOR_MAGENTA;
    extern color_t COLOR_CYAN;

    extern color_t COLOR_TEXT_DEFAULT;
    extern color_t COLOR_BACKGROUND_DEFAULT;

    extern uint8_t MAC_BACKGROUND_OFFSET;
    extern std::string MAC_CHAR_CODE_PRE;
    extern std::string MAC_CHAR_CODE_POST;

    int SetConsoleColor(color_t text, color_t background, bool bold_text = true, bool debug = false);
    int SetConsoleColor(color_t background, bool bold_text = true, bool debug = false);
    int ResetConsoleColor(bool bold_text = true, bool debug = false);
}

#endif
