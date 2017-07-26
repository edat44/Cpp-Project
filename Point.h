#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

class Point
{
public:
    enum class DIRECTION : char;
private:
    int m_x = 0;
    int m_y = 0;
    
    Point& Shift(DIRECTION dir);
public:
    Point();
    Point(int x, int y);
    
    std::string Direction_name(DIRECTION dir);
    
    int X();
    int Y();
    Point& Shift(char direction_input);
    
    
    friend std::ostream& operator<<(std::ostream &out, const Point &point);
    friend Point operator+(const Point &p1, const Point &p2);
    
    Point& operator+=(const Point &p2);
    Point& operator-=(const Point &p2);
};



#endif