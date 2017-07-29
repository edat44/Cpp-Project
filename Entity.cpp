#include "Entity.h"

Entity::Entity(std::string name)
    : m_name(name)
{}


Entity::Entity(std::string name, const Point &pos, int health)
    : m_name(name), m_pos(pos), m_health(health)
{}
    
Point& Entity::GetPosition()
{
    return this->m_pos;
}

std::ostream& operator<<(std::ostream &out, const Entity &entity)
{
    out <<  "Name: " << entity.m_name << ", " <<
            "Health: " << entity.m_health << ", " <<
            "Position: " << entity.m_pos;
    return out;
}