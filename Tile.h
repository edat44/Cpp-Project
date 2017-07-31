#ifndef TILE_H
#define TILE_H

#include "SDL_F.h"
#include "LTexture.h"
#include "Map.h"
#include <memory>

//The tile
class Tile
{
    private:
        //The attributes of the tile
        SDL_Rect m_box;

        //The tile type
        int m_type;

        LTexture gTexture;
    public:
		//Initializes position and type
		Tile( int x, int y, int tile_type );

		static const int WIDTH = 80;
        static const int HEIGHT = 80;

        //The different tile sprites
        static const int TILE_RED = 0;
        static const int TILE_GREEN = 1;
        static const int TILE_BLUE = 2;
        static const int TILE_CENTER = 3;
        static const int TILE_TOP = 4;
        static const int TILE_TOPRIGHT = 5;
        static const int TILE_RIGHT = 6;
        static const int TILE_BOTTOMRIGHT = 7;
        static const int TILE_BOTTOM = 8;
        static const int TILE_BOTTOMLEFT = 9;
        static const int TILE_LEFT = 10;
        static const int TILE_TOPLEFT = 11;

		//Shows the tile
		void Render( SDL_Rect& camera, std::shared_ptr<Map> map);

		//Get the tile type
		int getType();

		//Get the collision box
		SDL_Rect getBox();
};
#endif // TILE_H
