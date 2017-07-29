#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Point.h"
#include <string>

class Player : public Entity
{
protected:
    
public:
    Player(const Point& point);
    Player(std::string name, const Point &point);
    
    bool Move(Map* map);
    
    std::string InputName();
};

#endif