#ifndef MAP_H
#define MAP_H

#include "Player.h"
#include <vector>
#include <iostream>
#include "Functions.h"
#include <cstdint>
#include <fstream>
#include <utility>
#include <memory>
#include <string>
#include "Tile.h"

struct Square
{
    const char ch;
    const color_t color;
};

using map_t = std::vector<std::shared_ptr<Tile>>;
using square_t = Square;//std::pair<char, color_t>;

class Map
{
public:
    static const int TOTAL_TILE_SPRITES = 12;
private:
    map_t m_tiles;

    std::vector<SDL_Rect> m_tile_clips(TOTAL_TILE_SPRITES);
    LTexture m_tile_texture;

    std::shared_ptr<Player> m_player;

    SDL_Rect m_camera;

    int m_width = 0;
    int m_height = 0;
public:
    Map();

    map_t& GetTiles();

    Player& GetPlayer();

    int TotalTiles();

    void Draw();

    Point Size();

    bool PlayerTurn();

    void Move();

    void SetCamera();

    void Render();

    void HandleEvent(SDL_Event &e);

    bool EncounterSpace(const Point& p);

    bool LoadTextures(std::string tile_path, std::string player_path);

    bool SetTiles(std::string file);

    std::vector<SDL_Rect> GetTileClips();

    void Free();
};

#endif
