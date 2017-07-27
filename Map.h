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
    Point m_size;
    Player m_player;
public:
    Map();
    
    Player& GetPlayer();
    
    map_t& CreateBlankMap(const Point &s);
    
    const Point& Size() const;
    
    void Draw();
    
    bool PlayerTurn();
};

#endif