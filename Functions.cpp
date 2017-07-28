#include "Functions.h"

namespace console
{
    
    uint8_t WINDOWS_RED =       0b0001;
    uint8_t WINDOWS_BLUE =      0b0010;
    uint8_t WINDOWS_GREEN =     0b0100;
    uint8_t WINDOWS_WHITE =     WINDOWS_RED | WINDOWS_BLUE | WINDOWS_GREEN;
    uint8_t WINDOWS_BLACK =     0;
    uint8_t WINDOWS_PURPLE =    WINDOWS_RED | WINDOWS_BLUE;
    uint8_t WINDOWS_YELLOW =    WINDOWS_RED | WINDOWS_GREEN;
    uint8_t WINDOWS_CYAN =      WINDOWS_BLUE | WINDOWS_GREEN;
    
    uint8_t WINDOWS_INTENSITY = 0b1000;
        
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
            
            if (text & WINDOWS_RED)
                wAttributes |= FOREGROUND_RED;
            if (text & WINDOWS_BLUE)
                wAttributes |= FOREGROUND_BLUE;
            if (text & WINDOWS_GREEN)
                wAttributes |= FOREGROUND_GREEN;
            if (text & WINDOWS_INTENSITY)
                wAttributes |= FOREGROUND_INTENSITY;
                
            if (background & WINDOWS_RED)
                wAttributes |= BACKGROUND_RED;
            if (background & WINDOWS_BLUE)
                wAttributes |= BACKGROUND_BLUE;
            if (background & WINDOWS_GREEN)
                wAttributes |= BACKGROUND_GREEN;
            if (background & WINDOWS_INTENSITY)
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
        return SetConsoleColor(WINDOWS_WHITE | WINDOWS_INTENSITY, WINDOWS_BLACK);
    }
}