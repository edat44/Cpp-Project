#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <sstream>

class Position
{
private:
    int m_x = 0;
    int m_y = 0;
public:
    Position();
    Position(int x, int y);
    
    enum class DIRECTION : char;
    
    int X();
    int Y();
    std::string Print();
    void Shift(DIRECTION direction);
};

#endif