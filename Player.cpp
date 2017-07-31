#include "Player.h"
#include <iostream>
#include "Map.h"

Player::Player(int x, int y)
    : Player(this->InputName(), x, y)
{}

Player::Player(std::string name, int x, int y)
    : Entity(name, x, y, WIDTH, HEIGHT, STARTING_HEALTH)
{}

/*
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
*/


void Player::Move(std::shared_ptr<Map> map)
{
    //Move the dot left or right
    m_box.x += m_vel_x;

    //If the dot went too far to the left or right or touched a wall
    if( ( m_box.x < 0 ) || ( m_box.x + this->WIDTH > map->Size().x ) || SDL::touchesWall( m_box, map->GetTiles() ) )
    {
        //move back
        m_box.x -= m_vel_x;
    }

    //Move the dot up or down
    m_box.y += m_vel_y;

    //If the dot went too far up or down or touched a wall
    if( ( m_box.y < 0 ) || ( m_box.y + this->HEIGHT > map->Size().y ) || SDL::touchesWall( m_box, map->GetTiles() ) )
    {
        //move back
        m_box.y -= m_vel_y;
    }
}
*/

void Player::HandleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: m_vel_y -= Player::VEL; break;
            case SDLK_DOWN: m_vel_y += Player::VEL; break;
            case SDLK_LEFT: m_vel_x -= Player::VEL; break;
            case SDLK_RIGHT: m_vel_x += Player::VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: m_vel_y += Player::VEL; break;
            case SDLK_DOWN: m_vel_y -= Player::VEL; break;
            case SDLK_LEFT: m_vel_x += Player::VEL; break;
            case SDLK_RIGHT: m_vel_x -= Player::VEL; break;
        }
    }
}

std::string Player::InputName()
{
    std::string name;
    std::cout << "Enter player name: ";
    std::cin >> name;
    return name;
}
