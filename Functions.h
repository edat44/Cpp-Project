#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdint>
#include <iostream>
#include <Windows.h>

namespace func
{
    
}

namespace console
{
    static uint8_t WINDOWS_RED =       0b0001;
    static uint8_t WINDOWS_BLUE =      0b0010;
    static uint8_t WINDOWS_GREEN =     0b0100;
    static uint8_t WINDOWS_INTENSITY = 0b1000;
    
    int SetConsoleColor(uint8_t foreground, uint8_t background);
    int ResetConsoleColor();
}

#endif