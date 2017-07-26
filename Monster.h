#ifndef MONSTER_H
#define MONSTER_H

#include "Entity.h"

class Monster : public Entity
{
protected:
    
public:
    Monster();
    
    bool Move();
};

#endif