#include "Monster.h"
#include <iostream>

Monster::Monster()
    : Entity("MONSTER")
{}
    
bool Monster::Move()
{
    std::cout << "I AM MOVING!" << std::endl;
    return false;
}