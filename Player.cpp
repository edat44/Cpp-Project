#include "Player.h"
#include <iostream>

Player::Player()
    : Entity("player")
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