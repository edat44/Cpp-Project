#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include "Functions.h"
#include <cstdint>

using map_t = std::vector<std::vector<char>>;

class Map
{
private:
    map_t m_map {{}};
    Player m_player;
public:
    Map();
    
    const unsigned char WALL = 'W';
    const uint8_t WALL_COLOR = console::COLOR_RED;
    
    Player& GetPlayer();
    
    map_t& CreateBlankMap(const Point &s);
    map_t& AddBorder();
    
    const Point Size() const;
    
    void Draw();
    
    bool PlayerTurn();
    
    bool ValidSpace(const Point& p);
};

#endif