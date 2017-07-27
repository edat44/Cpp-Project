#include "Map.h"

Map::Map()
    : m_player(Player())
{}

const Point& Map::Size() const
{
    return this->m_size; 
}

Player& Map::GetPlayer()
{
    return this->m_player;
}

map_t& Map::CreateBlankMap(const Point& s)
{
    this->m_size = s;
    this->m_map.resize(s.Y());
    for(int y = 0; y < s.Y(); ++y)
    {
        for (int x = 0; x < s.X(); ++x)
        {
            this->m_map.at(y).push_back('a');
        }
    }
}

bool Map::PlayerTurn()
{
    this->Draw();
    std::cout << this->m_player << std::endl;
    return this->m_player.Move();    
}

void Map::Draw()
{
    for (int y = 0; y < this->m_size.Y(); ++y)
    {
        for (int x = 0; x < this->m_size.X(); ++x)
        {
            Point currentPoint = Point(x, y);
            char c = this->m_map.at(y).at(x);
            if (this->m_player.GetPosition() == currentPoint)
                c = '*';
            std::cout << c;
        }
        std::cout << std::endl;
    }
}