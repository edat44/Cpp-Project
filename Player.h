#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Point.h"
#include <string>

class Player : public Entity
{
protected:
    
public:
    Player();
    Player(std::string name);
    
    bool Move();
    
    std::string InputName();
};

#endif