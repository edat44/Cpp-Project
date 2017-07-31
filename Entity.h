#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "SDL_F.h"
#include "LTexture.h"

class Entity
{
protected:
    std::string m_name;
    int m_health = 10;
    SDL_Rect m_box;
    int m_vel_x;
    int m_vel_y;
    LTexture *m_texture;
public:
    Entity(std::string name, int width, int height);
    Entity(std::string name, int x, int y, int width, int height, int health = 10);

    virtual bool Move(Map* map) = 0;

    virtual bool Handle_event(SDL_Event &e) = 0;

    virtual bool LoadTexture(std::string path);

    //Centers the camera over the dot
    void SetCamera( SDL_Rect& camera );

    //Shows the dot on the screen
    void Render( SDL_Rect& camera );


    friend std::ostream& operator<<(std::ostream &out, const Entity &entity);

    void Free();

};

#endif
