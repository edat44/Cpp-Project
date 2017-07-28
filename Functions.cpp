#include "Functions.h"

namespace func
{
    bool OSTest()
    {
#if PLATFORM_NAME == WINDOWS
        std::cout << "Running Windows" << std::endl;
        return true;
#elif PLATFORM_NAME == OSX
        std::cout << "Running OSX" << std::endl;
        return true;
#else
        std::cout << "Running Undefined OS" << std::endl;
        return false;
#endif
    }
}

namespace console
{
#if PLATFORM_NAME == WINDOWS
    color_t COLOR_RED =       0b0001;
    color_t COLOR_BLUE =      0b0010;
    color_t COLOR_GREEN =     0b0100;
    color_t COLOR_INTENSITY = 0b1000;
        
    color_t COLOR_WHITE =     COLOR_RED | COLOR_BLUE | COLOR_GREEN;
    color_t COLOR_BLACK =     0;
    color_t COLOR_PURPLE =    COLOR_RED | COLOR_BLUE;
    color_t COLOR_YELLOW =    COLOR_RED | COLOR_GREEN;
    color_t COLOR_CYAN =      COLOR_BLUE | COLOR_GREEN;
#elif PLATFORM_NAME == OSX
    //Define Mac Colors Here
#else
    //Uhhhhh
#endif
    
        
    int SetConsoleColor(color_t text, color_t background, bool debug)
    {
#if PLATFORM_NAME == WINDOWS    
        HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
        if (hStdout == INVALID_HANDLE_VALUE) 
        {
            if (debug)
                std::cout << "Error while getting input handle" << std::endl;
            return EXIT_FAILURE;
        }
        
        uint16_t wAttributes = 0;
        
        if (text & COLOR_RED)
            wAttributes |= FOREGROUND_RED;
        if (text & COLOR_BLUE)
            wAttributes |= FOREGROUND_BLUE;
        if (text & COLOR_GREEN)
            wAttributes |= FOREGROUND_GREEN;
        if (text & COLOR_INTENSITY)
            wAttributes |= FOREGROUND_INTENSITY;
            
        if (background & COLOR_RED)
            wAttributes |= BACKGROUND_RED;
        if (background & COLOR_BLUE)
            wAttributes |= BACKGROUND_BLUE;
        if (background & COLOR_GREEN)
            wAttributes |= BACKGROUND_GREEN;
        if (background & COLOR_INTENSITY)
            wAttributes |= BACKGROUND_INTENSITY;
            
        SetConsoleTextAttribute(hStdout, wAttributes);
        
        return EXIT_SUCCESS;
#elif PLATFORM_NAME == OSX
        return EXIT_SUCCESS;
#else
        return EXIT_FAILURE;
#endif
    }
    
    int ResetConsoleColor(bool debug)
    {
        return SetConsoleColor(COLOR_WHITE | COLOR_INTENSITY, COLOR_BLACK);
    }
}