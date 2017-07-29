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
    color_t COLOR_BOLD = 0b1000;
    
    color_t COLOR_RED =         0b0001;
    color_t COLOR_BLUE =        0b0010;
    color_t COLOR_GREEN =       0b0100;
    color_t COLOR_WHITE =       COLOR_RED | COLOR_BLUE | COLOR_GREEN;
    color_t COLOR_BLACK =       0;
    color_t COLOR_MAGENTA =     COLOR_RED | COLOR_BLUE;
    color_t COLOR_YELLOW =      COLOR_RED | COLOR_GREEN;
    color_t COLOR_CYAN =        COLOR_BLUE | COLOR_GREEN;
    
    color_t COLOR_RED_BOLD =    COLOR_RED | COLOR_BOLD;
    color_t COLOR_BLUE_BOLD =   COLOR_BLUE | COLOR_BOLD;
    color_t COLOR_GREEN_BOLD =  COLOR_GREEN | COLOR_BOLD;
    color_t COLOR_WHITE_BOLD =  COLOR_WHITE | COLOR_BOLD;
    color_t COLOR_BLACK_BOLD =  COLOR_BLACK |COLOR_BOLD;
    color_t COLOR_MAGENTA_BOLD =COLOR_MAGENTA | COLOR_BOLD;
    color_t COLOR_YELLOW_BOLD = COLOR_YELLOW | COLOR_BOLD;
    color_t COLOR_CYAN_BOLD =   COLOR_CYAN | COLOR_BOLD;
    
#elif PLATFORM_NAME == OSX
    color_t COLOR_BOLD =        100;
    
    color_t COLOR_RED =         31;
    color_t COLOR_BLUE =        34;
    color_t COLOR_GREEN =       32;
    color_t COLOR_WHITE =       37;
    color_t COLOR_BLACK =       30;
    color_t COLOR_MAGENTA =     35;
    color_t COLOR_YELLOW =      33;
    color_t COLOR_CYAN =        36;
    
    color_t COLOR_RED_BOLD =    COLOR_RED + COLOR_BOLD;
    color_t COLOR_BLUE_BOLD =   COLOR_BLUE + COLOR_BOLD;
    color_t COLOR_GREEN_BOLD =  COLOR_GREEN + COLOR_BOLD;
    color_t COLOR_WHITE_BOLD =  COLOR_WHITE + COLOR_BOLD;
    color_t COLOR_BLACK_BOLD =  COLOR_BLACK +COLOR_BOLD;
    color_t COLOR_MAGENTA_BOLD =COLOR_MAGENTA + COLOR_BOLD;
    color_t COLOR_YELLOW_BOLD = COLOR_YELLOW + COLOR_BOLD;
    color_t COLOR_CYAN_BOLD =   COLOR_CYAN + COLOR_BOLD;
#else
    //Uhhhhh
#endif
    
    uint8_t MAC_BACKGROUND_OFFSET = 10;
    std::string MAC_CHAR_CODE_PRE = "\x1b[";
    std::string MAC_CHAR_CODE_POST = "m";
    
        
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
        if (text & COLOR_BOLD)
            wAttributes |= FOREGROUND_INTENSITY;
            
        if (background & COLOR_RED)
            wAttributes |= BACKGROUND_RED;
        if (background & COLOR_BLUE)
            wAttributes |= BACKGROUND_BLUE;
        if (background & COLOR_GREEN)
            wAttributes |= BACKGROUND_GREEN;
        if (background & COLOR_BOLD)
            wAttributes |= BACKGROUND_INTENSITY;
            
        SetConsoleTextAttribute(hStdout, wAttributes);
        
        return EXIT_SUCCESS;
#elif PLATFORM_NAME == OSX
        if (text > COLOR_BOLD)
        {
            std::cout << MAC_CHAR_CODE_PRE << 1 << MAC_CHAR_CODE_POST;
            text -= COLOR_BOLD;
        }
        if (background > COLOR_BOLD)
        {
            background -= COLOR_BOLD;
        }
        std::cout << MAC_CHAR_CODE_PRE << text << MAC_CHAR_CODE_POST;
        std::cout << MAC_CHAR_CODE_PRE << (background + MAC_BACKGROUND_OFFSET) << MAC_CHAR_CODE_POST;
        return EXIT_SUCCESS;
#else
        return EXIT_FAILURE;
#endif
    }
    
    int ResetConsoleColor(bool debug)
    {
        return SetConsoleColor(COLOR_WHITE_BOLD, COLOR_BLACK);
    }
}