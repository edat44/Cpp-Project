#include "Player.h"
#include <iostream>

Player::Player()
    : Player(this->InputName())
{}
    
Player::Player(std::string name)
    : Entity(name)
{}

bool Player::Move()
{
    char shift;
    std::cout << "Move using wasd, or 'x' to exit: ";
    std::cin >> shift;
    if (shift == 'x')
        return true;
    this->m_pos.Shift(shift);

    return false;
}

std::string Player::InputName()
{
    std::string name;
    std::cout << "Enter player name: ";
    std::cin >> name;
    return name;
}