#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

class Point
{
private:
    int m_x = 0;
    int m_y = 0;
public:
    Point();
    Point(int x, int y);
    
    enum class DIRECTION : char;
    std::string Direction_name(DIRECTION dir);
    
    int X();
    int Y();
    Point& Shift(char direction_input);
    Point& Shift(DIRECTION direction);
    
    friend std::ostream& operator<<(std::ostream &out, const Point &point);
    friend Point operator+(const Point &p1, const Point &p2);
    
    Point& operator+=(const Point &p2);
    Point& operator-=(const Point &p2);
};



#endif