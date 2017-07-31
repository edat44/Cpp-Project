#include "Entity.h"

Entity::Entity(std::string name, int width, int height)
    : Entity(name, 0, 0, width, height)
{}


Entity::Entity(std::string name, int x, int y, int width, int height, int health)
{
    this->m_name = name;
    this->m_box.x = x;
    this->m_box.y = y;
    this->m_box.w = width;
    this->m_box.h = height;
    this->m_vel_x = 0;
    this->m_vel_y = 0;
    this->gTexture = NULL;
}

std::ostream& operator<<(std::ostream &out, const Entity &entity)
{
    out <<  "Name: " << entity.m_name << ", " <<
            "Health: " << entity.m_health << ", " <<
            "Position: " << entity.m_pos;
    return out;
}

bool Entity::LoadTexture(std::string path)
{
    return this->m_texture.loadFromFile(path);
}

void Entity::setCamera( SDL_Rect& camera )
{
	//Center the camera over the dot
	camera.x = ( mBox.x + DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2;
	camera.y = ( mBox.y + DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

	//Keep the camera in bounds
	if( camera.x < 0 )
	{
		camera.x = 0;
	}
	if( camera.y < 0 )
	{
		camera.y = 0;
	}
	if( camera.x > LEVEL_WIDTH - camera.w )
	{
		camera.x = LEVEL_WIDTH - camera.w;
	}
	if( camera.y > LEVEL_HEIGHT - camera.h )
	{
		camera.y = LEVEL_HEIGHT - camera.h;
	}
}

void Entity::render( SDL_Rect& camera )
{
    //Show the dot
	gDotTexture.render( mBox.x - camera.x, mBox.y - camera.y );
}

void Entity::Free()
{
    this->m_texture.free();
}
