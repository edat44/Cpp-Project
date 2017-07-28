#include "Functions.h"

namespace console
{
#if defined(_WIN32) || defined(_WIN64)
    uint8_t COLOR_RED =       0b0001;
    uint8_t COLOR_BLUE =      0b0010;
    uint8_t COLOR_GREEN =     0b0100;
    uint8_t COLOR_INTENSITY = 0b1000;
        
    uint8_t COLOR_WHITE =     COLOR_RED | COLOR_BLUE | COLOR_GREEN;
    uint8_t COLOR_BLACK =     0;
    uint8_t COLOR_PURPLE =    COLOR_RED | COLOR_BLUE;
    uint8_t COLOR_YELLOW =    COLOR_RED | COLOR_GREEN;
    uint8_t COLOR_CYAN =      COLOR_BLUE | COLOR_GREEN;
#elif defined(__MAC__) || defined(__MACH__)
    //Define Mac Colors Here
    
#else
    //Uhhhh
#endif
    
        
    int SetConsoleColor(uint8_t text, uint8_t background, bool debug)
    {
#if defined(_WIN32) || defined(_WIN64)
        if (debug)
            std::cout << "WINDOWS" << std::endl;
            
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
#elif defined(__MAC__) || defined(__MACH__)
        if (debug)
            std::cout << "MAC" << std::endl;
        return EXIT_SUCCESS;
#else
        if (debug)
            std::cout << "NEITHER WINDOWS NOR MAC" << std::endl;
        return EXIT_FAILURE;
#endif
    }
    
    int ResetConsoleColor(bool debug)
    {
        return SetConsoleColor(COLOR_WHITE | COLOR_INTENSITY, COLOR_BLACK);
    }
}