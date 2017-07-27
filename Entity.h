#ifndef ENTITY_H
#define ENTITY_H

#include "Point.h"
#include <string>

class Entity
{
protected:
    std::string m_name;
    int m_health = 10;
    Point m_pos = Point();
public:
    Entity(std::string name);
    Entity(std::string name, const Point &pos, int health = 10);
    
    virtual bool Move() = 0;
    
    Point& GetPosition();
    
    friend std::ostream& operator<<(std::ostream &out, const Entity &entity);
};

#endif