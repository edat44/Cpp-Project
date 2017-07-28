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
    extern uint8_t WINDOWS_RED;
    extern uint8_t WINDOWS_BLUE;
    extern uint8_t WINDOWS_GREEN;
    extern uint8_t WINDOWS_WHITE;
    extern uint8_t WINDOWS_BLACK;
    extern uint8_t WINDOWS_INTENSITY;
    
    int SetConsoleColor(uint8_t foreground, uint8_t background, bool debug = false);
    int ResetConsoleColor(bool debug = false);
}

#endif