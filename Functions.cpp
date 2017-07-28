#include "Functions.h"

namespace console
{
    
    int SetConsoleColor(uint8_t text, uint8_t background)
    {
        #if defined(_WIN32) || defined(_WIN64)
            std::cout << "WINDOWS" << std::endl;
            HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
            if (hStdout == INVALID_HANDLE_VALUE) 
            {
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
            std::cout << "MAC" << std::endl;
            return EXIT_SUCCESS;
        #else
            std::cout << "NEITHER WINDOWS NOR MAC" << std::endl;
            return EXIT_FAILURE;
        #endif
    }
    
    int ResetConsoleColor()
    {
        return SetConsoleColor(WINDOWS_RED | WINDOWS_BLUE | WINDOWS_GREEN | WINDOWS_INTENSITY, 0);
    }
}