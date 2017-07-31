#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Functions.h"
#include "SDL_F.h"
#include <string>

class Map;

class Player : Entity
{
public:
    Player(int x, int y);
    Player(std::string name, int x, int y);

    //The dimensions of the dot
	static const int WIDTH = 20;
	static const int HEIGHT = 20;
	static const int STARTING_HEALTH = 100;

    //Maximum axis velocity of the dot
    static const int VEL = 10;

    bool Move(Map* map);

    //Moves the dot and check collision against tiles
    //void move( Tile *tiles[] );



    //Takes key presses and adjusts the dot's velocity
    void HandleEvent( SDL_Event& e );

    std::string InputName();
};

#endif
