#include "Position.h"

Position::Position() {}

Position::Position(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

enum class Position::DIRECTION : char
{
    LEFT = 'a',
    RIGHT = 'd',
    UP = 'w',
    DOWN = 's'
};


int Position::X()
{
    return this->m_x;
}

int Position::Y()
{
    return this->m_y;
}

std::string Position::Print()
{
    std::ostringstream s;
    s << "(" << this->m_x << ", " << this->m_y << ")";
    return s.str();
}

void Position::Shift(Position::DIRECTION direction)
{
    return;
}