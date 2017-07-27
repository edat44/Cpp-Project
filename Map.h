#ifndef MAP_H
#define MAP_H

#include "Point.h"
#include <vector>

class Map
{
private:
    std::vector<std::vector<char>> m_map {
        {'a', 'b'},
        {'c', 'd'},
        {'e', 'f'}
    };
public:
    Map();
    
    Point Size();
};

#endif