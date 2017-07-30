#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

class Map;
class Player;

class Point
{
public:
    enum class DIRECTION : char;
private:
    int m_x = 0;
    int m_y = 0;

    Point& Shift(DIRECTION dir, Player *player = nullptr, Map *map = nullptr);
public:
    Point();
    Point(int x, int y);
    
    std::string DirectionName(DIRECTION dir);
    
    int X() const;
    int Y() const;
    
    Point& Shift(char direction_input, Player *player = nullptr, Map *map = nullptr);

    
    friend std::ostream& operator<<(std::ostream &out, const Point &point);
    friend Point operator+(const Point &p1, const Point &p2);
    
    Point& operator+=(const Point &p2);
    Point& operator-=(const Point &p2);
    bool operator==(const Point&p2);
};



#endif