#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include "Player.h"
#include <vector>
#include <iostream>

using map_t = std::vector<std::vector<char>>;

class Map
{
private:
    map_t m_map {{}};
    Player m_player;
public:
    Map();
    
    const unsigned char BORDER_V = '|';
    const unsigned char BORDER_H = '-';
    
    Player& GetPlayer();
    
    map_t& CreateBlankMap(const Point &s);
    map_t& AddBorder();
    
    const Point Size() const;
    
    void Draw();
    
    bool PlayerTurn();
    
    bool ValidSpace(const Point& p);
};

#endif