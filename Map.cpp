#include "Map.h"
#include "SDL_F.h"

Map::Map()
    :
{
    this->m_player = {Point(5, 5)};
    this->m_camera = { 0, 0, SDL::SCREEN_WIDTH, SDL::SCREEN_HEIGHT };
}

Tile[]& Map::GetTiles()
{
    return this->m_tiles;
}

Player& Map::GetPlayer()
{
    return this->m_player;
}

Point Map::Size()
{
    return {this->m_width * Tile::WIDTH, this->m_height * Tile::HEIGHT};
}

void Map::Move()
{
    this->m_player->Move(this->m_tiles);
}

int Map::TotalTiles()
{
    return this->m_width * this->m_height;
}

bool Map::PlayerTurn()
{
    this->Draw();
    std::cout << this->m_player << std::endl;
    return this->m_player.Move(this);
}

void Map::HandleEvent(SDL_Event &e)
{
    this->m_player->HandleEvent(e);
}

void Map::Draw()
{
    Point size = this->Size();
    char previous_square = ' ';
    for (int y = 0; y < size.Y(); ++y)
    {
        for (int x = 0; x < size.X(); ++x)
        {
            Point currentPoint = Point(x, y);
            char c = this->m_map.at(y).at(x);

            bool sqaure_type_found = false;
            for (square_t sqaure : SQUARE_TYPES)
            {
                if (c == sqaure.ch)
                {
                    if (x == 0 || previous_square != c)
                        console::SetConsoleColor(sqaure.color, true);
                    previous_square = c;
                    c = ' ';
                    sqaure_type_found = true;
                    break;
                }
            }
            if (!sqaure_type_found)
            {
                std::cerr << "INVALID SQUARE IN MAP: " << c << std::endl;
            }

            if (this->m_player.GetPosition() == currentPoint)
                c = PLAYER;

            std::cout << c;
        }
        console::ResetConsoleColor();
        std::cout << std::endl;
    }
    console::ResetConsoleColor();
}

bool Map::EncounterSpace(const Point &p)
{
    const char c = this->m_map.at(p.Y()).at(p.X());
    if (c == SQUARE_EMPTY.ch)
    {
        return true;
    }
    else if (c == SQUARE_DOOR.ch)
    {
        return true;
    }
    else if (c == SQUARE_WALL.ch)
    {
        return false;
    }
    else if (c == SQUARE_MONSTER.ch)
    {
        return false;
    }
    else
    {
        return false;
    }
}

bool Map::LoadTileTexture(std::string tile_path, std::string player_path)
{
    return this->m_tile_texture.loadFromFile(tile_path) && this->m_player->LoadTexture(player_path);
}

bool Map::SetTiles(std::string file)
{
	//Success flag
	bool tilesLoaded = true;

    //The tile offsets
    int x = 0, y = 0;

    //Open the map
    std::ifstream map_file(func::GetFile(file).c_str());

    //If the map couldn't be loaded
    if( map_file == NULL )
    {
		printf( "Unable to load map file!\n" );
		tilesLoaded = false;
    }
	else
	{
	    std::string row_data;
		//Initialize the tiles
        while (std::getline(map_file, row_data))
        {
            x = 0;
            std::istreamstream iss(row_data);
            int tileType = -1;

            while (iss >> tileType)
            {
                //If the number is a valid tile number
                if( ( tileType >= 0 ) && ( tileType < TOTAL_TILE_SPRITES ) )
                {
                    m_tiles.push_back(std::make_shared<Tile>(x, y, tileType);
                }
                //If we don't recognize the tile type
                else
                {
                    //Stop loading map
                    printf( "Error loading map: Invalid tile type at %d!\n", i );
                    tilesLoaded = false;
                    break;
                }
                x += Tile::WIDTH;
            }
            if (tiles_loaded == false)
                break;

			y += Tile::HEIGHT;
		}

		//Clip the sprite sheet
		if( tilesLoaded )
		{
			m_tile_clips[ TILE_RED ].x = 0;
			m_tile_clips[ TILE_RED ].y = 0;
			m_tile_clips[ TILE_RED ].w = Tile::WIDTH;
			m_tile_clips[ TILE_RED ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_GREEN ].x = 0;
			m_tile_clips[ TILE_GREEN ].y = 1 * Tile::HEIGHT;
			m_tile_clips[ TILE_GREEN ].w = Tile::WIDTH;
			m_tile_clips[ TILE_GREEN ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_BLUE ].x = 0;
			m_tile_clips[ TILE_BLUE ].y = 2 * Tile::HEIGHT;
			m_tile_clips[ TILE_BLUE ].w = Tile::WIDTH;
			m_tile_clips[ TILE_BLUE ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_TOPLEFT ].x = 1 * Tile::WIDTH;
			m_tile_clips[ TILE_TOPLEFT ].y = 0;
			m_tile_clips[ TILE_TOPLEFT ].w = Tile::WIDTH;
			m_tile_clips[ TILE_TOPLEFT ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_LEFT ].x = 1 * Tile::WIDTH;
			m_tile_clips[ TILE_LEFT ].y = 1 * Tile::HEIGHT;
			m_tile_clips[ TILE_LEFT ].w = Tile::WIDTH;
			m_tile_clips[ TILE_LEFT ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_BOTTOMLEFT ].x = 1 * Tile::WIDTH;
			m_tile_clips[ TILE_BOTTOMLEFT ].y = 2 * Tile::HEIGHT;
			m_tile_clips[ TILE_BOTTOMLEFT ].w = Tile::WIDTH;
			m_tile_clips[ TILE_BOTTOMLEFT ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_TOP ].x = 2 * Tile::WIDTH;
			m_tile_clips[ TILE_TOP ].y = 0;
			m_tile_clips[ TILE_TOP ].w = Tile::WIDTH;
			m_tile_clips[ TILE_TOP ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_CENTER ].x = 2 * Tile::WIDTH;
			m_tile_clips[ TILE_CENTER ].y = 1 * Tile::HEIGHT;
			m_tile_clips[ TILE_CENTER ].w = Tile::WIDTH;
			m_tile_clips[ TILE_CENTER ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_BOTTOM ].x = 2 * Tile::WIDTH;
			m_tile_clips[ TILE_BOTTOM ].y = 2 * Tile::HEIGHT;
			m_tile_clips[ TILE_BOTTOM ].w = Tile::WIDTH;
			m_tile_clips[ TILE_BOTTOM ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_TOPRIGHT ].x = 3 * Tile::WIDTH;
			m_tile_clips[ TILE_TOPRIGHT ].y = 0;
			m_tile_clips[ TILE_TOPRIGHT ].w = Tile::WIDTH;
			m_tile_clips[ TILE_TOPRIGHT ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_RIGHT ].x = 3 * Tile::WIDTH;
			m_tile_clips[ TILE_RIGHT ].y = 1 * Tile::HEIGHT;
			m_tile_clips[ TILE_RIGHT ].w = Tile::WIDTH;
			m_tile_clips[ TILE_RIGHT ].h = Tile::HEIGHT;

			m_tile_clips[ TILE_BOTTOMRIGHT ].x = 3 * Tile::WIDTH;
			m_tile_clips[ TILE_BOTTOMRIGHT ].y = 2 * Tile::HEIGHT;
			m_tile_clips[ TILE_BOTTOMRIGHT ].w = Tile::WIDTH;
			m_tile_clips[ TILE_BOTTOMRIGHT ].h = Tile::HEIGHT;
		}
	}

    //Close the file
    map_file.close();

    //If the map was loaded fine
    return tilesLoaded;
}

void Map::SetCamera()
{
    this->m_player->setCamera(this->m_camera)
}

void Map::Render()
{
    for (std::shared_ptr<Tile> tile : this->m_tiles)
    {
        tile->Render(this->m_camera, this);
    }
    this->m_player->render(this->m_camera)
}

std::vector<SDL_Rect> Map::GetTileClips()
{
    return this->m_tile_clips;
}

void Map::Free()
{
    for( int i = 0; i < map.size(); ++i )
        {
             if( tiles.at(i) == NULL )
             {
                delete tiles[ i ];
                tiles[ i ] = NULL;
             }
        }

        //Free loaded images
        this->m_player->Free();
        m_tile_texture.free();
}
