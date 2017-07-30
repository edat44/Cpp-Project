#include "Player.h"
#include <iostream>

#include "Map.h"

Player::Player(const Point &point)
    : Player(this->InputName(), point)
{}
    
Player::Player(std::string name, const Point &point)
    : Entity(name, point)
{}

bool Player::Move(Map* map)
{
    char shift;
    std::cout << "Move using wasd, or 'x' to exit: ";
    std::cin >> shift;
    if (shift == 'x')
        return true;
    this->m_pos.Shift(shift, this, map);

    return false;
}

std::string Player::InputName()
{
    std::string name;
    std::cout << "Enter player name: ";
    std::cin >> name;
    return name;
}