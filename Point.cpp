#include "Point.h"

Point::Point() {}

Point::Point(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

enum class Point::DIRECTION : char
{
    LEFT = 'a',
    RIGHT = 'd',
    UP = 'w',
    DOWN = 's'
};

std::string Point::Direction_name(DIRECTION dir)
{
    switch(dir)
    {
        case DIRECTION::LEFT:
            return "left";
        case DIRECTION::RIGHT:
            return "right";
        case DIRECTION::UP:
            return "up";
        case DIRECTION::DOWN:
            return "down";
        default:
            std::cerr << "INVALID DIRECTION: Point::Direction_name()" << std::endl;
            break;
    }
}


int Point::X()
{
    return this->m_x;
}

int Point::Y()
{
    return this->m_y;
}

Point& Point::Shift(char direction_input) {
    DIRECTION dir = static_cast<DIRECTION>(direction_input);
    switch(dir)
    {
        case DIRECTION::LEFT:
        case DIRECTION::RIGHT:
        case DIRECTION::UP:
        case DIRECTION::DOWN:
            return this->Shift(dir);
        default:
            std::cerr << "INVALID DIRECTION: Point:Shift(char)" << std::endl;
            return *this;
    }
}

Point& Point::Shift(Point::DIRECTION dir)
{
    std::cout << "shifting " << this->Direction_name(dir) << std::endl;
    switch(dir)
    {
        case DIRECTION::LEFT:
            --this->m_x;
            break;
        case DIRECTION::RIGHT:
            ++this->m_x;
            break;
        case DIRECTION::UP:
            --this->m_y;
            break;
        case DIRECTION::DOWN:
            ++this->m_y;
            break;
        default:
            std::cerr << "INVALID DIRECTION: Point::Shift(DIRECTION)" << std::endl;
            break;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Point &point)
{
    out << "(" << point.m_x << ", " << point.m_y << ")";
    return out;
}

Point operator+(const Point &p1, const Point &p2)
{
    return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
}

Point& Point::operator+=(const Point &p2)
{
    this->m_x += p2.m_x;
    this->m_y += p2.m_y;
    return *this;
}

Point& Point::operator-=(const Point &p2)
{
    this->m_x -= p2.m_x;
    this->m_y -= p2.m_y;
    return *this;
}