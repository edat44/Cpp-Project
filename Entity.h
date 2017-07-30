#ifndef ENTITY_H
#define ENTITY_H

#include "Point.h"
#include <string>

class Map;

class Entity
{
protected:
    std::string m_name;
    Point m_pos;
    int m_health = 10;
public:
    Entity(std::string name);
    Entity(std::string name, const Point &pos, int health = 10);

    virtual bool Move(Map* map) = 0;

    Point& GetPosition();

    friend std::ostream& operator<<(std::ostream &out, const Entity &entity);
};

#endif
