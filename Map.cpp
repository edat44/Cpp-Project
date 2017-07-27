#include "Map.h"

Map::Map()
{
    
}

Point Map::Size()
{
    return Point(this->m_map.at(0).size(), this->m_map.size());
}