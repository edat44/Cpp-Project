#include "Point.h"

#include "Map.h"

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

std::string Point::DirectionName(DIRECTION dir)
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
            std::cerr << "INVALID DIRECTION: Point::DirectionName()" << std::endl;
            return "ERROR";
    }
}


int Point::X() const
{
    return this->m_x;
}

int Point::Y() const
{
    return this->m_y;
}

Point& Point::Shift(char direction_input, Map* map)
{
    DIRECTION dir = static_cast<DIRECTION>(direction_input);
    switch(dir)
    {
        case DIRECTION::LEFT:
        case DIRECTION::RIGHT:
        case DIRECTION::UP:
        case DIRECTION::DOWN:
            return this->Shift(dir, map);
        default:
            std::cerr << "INVALID DIRECTION: Point:Shift(char)" << std::endl;
            return *this;
    }
}

Point& Point::Shift(Point::DIRECTION dir, Map* map)
{
    bool err = false;
    int x_temp = this->m_x, y_temp = this->m_y;
    switch(dir)
    {
        case DIRECTION::LEFT:
            --x_temp;
            break;
        case DIRECTION::RIGHT:
            ++x_temp;
            break;
        case DIRECTION::UP:
            --y_temp;
            break;
        case DIRECTION::DOWN:
            ++y_temp;
            break;
        default:
            std::cerr << "INVALID DIRECTION: Point::Shift(DIRECTION)" << std::endl;
            err = true;
            break;
    }
    if ((!map || map && map->ValidSpace(Point(x_temp, y_temp))) && !err)
    {
        this->m_x = x_temp;
        this->m_y = y_temp;
        std::cout << "shifting " << this->DirectionName(dir) << std::endl;
    }
    else
    {
        std::cout << "cannot shift " << this->DirectionName(dir) << std::endl;
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

bool Point::operator==(const Point &p2)
{
    return (this->m_x == p2.m_x && this->m_y == p2.m_y);
}