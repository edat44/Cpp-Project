#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include "Functions.h"
#include <cstdint>
#include <fstream>

using map_t = std::vector<std::vector<char>>;

class Map
{
private:
    map_t m_map {{}};
    Player m_player;
public:
    Map();

    const unsigned char END = 'E';
    const unsigned char WALL = 'W';
    const color_t WALL_COLOR = console::COLOR_RED;

    Player& GetPlayer();

    map_t& CreateBlankMap(const Point &s);

    map_t& CreateMapFromFile(std::string file);

    map_t& AddBorder();

    const Point Size() const;

    void Draw();

    bool PlayerTurn();

    bool ValidSpace(const Point& p);
};

#endif
