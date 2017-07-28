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
    extern uint8_t COLOR_RED;
    extern uint8_t COLOR_BLUE;
    extern uint8_t COLOR_GREEN;
    extern uint8_t COLOR_INTENSITY;
    
    extern uint8_t COLOR_WHITE;
    extern uint8_t COLOR_BLACK;
    extern uint8_t COLOR_YELLOW;
    extern uint8_t COLOR_PURPLE;
    extern uint8_t COLOR_CYAN;

    
    int SetConsoleColor(uint8_t foreground, uint8_t background, bool debug = false);
    int ResetConsoleColor(bool debug = false);
}

#endif