#include "Tile.h"


Tile::Tile( int x, int y, int tileType)
{
    //Get the offsets
    this->m_box.x = x;
    this->m_box.y = y;

    //Set the collision box
    this->m_box.w = WIDTH;
    this->m_box.h = HEIGHT;

    //Get the tile type
    this->m_type = tile_type;

    this->gTexture = NULL;
}

void Tile::Render( SDL_Rect& camera, std::shared_ptr<Map> map)
{
    //If the tile is on screen
    if( checkCollision( camera, this->m_box ) )
    {
        //Show the tile
        gTexture.render( this->m_box.x - camera.x, this->m_box.y - camera.y, map->GetTileClips().at(this->m_type));
    }
}

int Tile::getType()
{
    return this->m_type;
}

SDL_Rect Tile::getBox()
{
    return this->m_box;
}
