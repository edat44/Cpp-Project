#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include "Functions.h"
#include <cstdint>
#include <fstream>
#include <utility>

struct Square
{
    const char ch;
    const color_t color;
};

using map_t = std::vector<std::vector<char>>;
using square_t = Square;//std::pair<char, color_t>;

class Map
{
private:
    map_t m_map;
    Player m_player;
public:
    Map();

    const unsigned char END = 'E';
    const unsigned char PLAYER = '*';
    const square_t SQUARE_EMPTY =   Square {' ', console::COLOR_BACKGROUND_DEFAULT}; //std::make_pair(' ', console::COLOR_BACKGROUND_DEFAULT);
    const square_t SQUARE_WALL =    Square {'W', console::COLOR_RED}; //std::make_pair('W', console::COLOR_RED);
    const square_t SQUARE_DOOR =    Square {'D', console::COLOR_BLUE}; //std::make_pair('D', console::COLOR_BLUE);
    const square_t SQUARE_MONSTER = Square {'M', console::COLOR_GREEN}; //std::make_pair('M', console::COLOR_GREEN);

    const std::vector<square_t> SQUARE_TYPES = {SQUARE_EMPTY, SQUARE_WALL, SQUARE_DOOR, SQUARE_MONSTER};

    Player& GetPlayer();

    map_t& CreateBlankMap(const Point &s);

    map_t& CreateMapFromFile(std::string file);

    map_t& AddBorder();

    const Point Size() const;

    void Draw();

    bool PlayerTurn();

    bool EncounterSpace(const Point& p);
};

#endif
