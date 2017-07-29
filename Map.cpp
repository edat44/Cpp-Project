#include "Map.h"

Map::Map()
    : m_player(Player(Point(5, 5)))
{}

const Point Map::Size() const
{
    return Point(this->m_map.at(0).size(), this->m_map.size()); 
}

Player& Map::GetPlayer()
{
    return this->m_player;
}

map_t& Map::CreateBlankMap(const Point& s)
{
    this->m_map.resize(s.Y());
    for(int y = 0; y < s.Y(); ++y)
    {
        for (int x = 0; x < s.X(); ++x)
        {
            this->m_map.at(y).push_back(' ');
        }
    }
    this->AddBorder();
    return this->m_map;
}

map_t& Map::AddBorder()
{    
    //Horzontal Border
    const std::vector<char> border_h(this->Size().X(), WALL);
    auto it = this->m_map.begin(); 
    it = this->m_map.insert(it, border_h);
    this->m_map.push_back(border_h);
    
    //Vertical Border
    for (int y = 0; y < this->Size().Y(); ++y)
    {
        auto it = this->m_map.at(y).begin();
        it = this->m_map.at(y).insert(it, WALL);
        this->m_map.at(y).push_back(WALL);
    }
    
    return this->m_map;
}

bool Map::PlayerTurn()
{
    this->Draw();
    std::cout << this->m_player << std::endl;
    return this->m_player.Move(this);    
}

void Map::Draw()
{
    Point size = this->Size();
    bool previous_wall = false;
    for (int y = 0; y < size.Y(); ++y)
    {
        for (int x = 0; x < size.X(); ++x)
        {
            Point currentPoint = Point(x, y);
            char c = this->m_map.at(y).at(x);
            if (this->m_player.GetPosition() == currentPoint)
                c = '*';
                
            if (c == WALL)
            {
                c = ' ';
                if (!previous_wall)
                    console::SetConsoleColor(WALL_COLOR, WALL_COLOR, false);
                previous_wall = true;
            }
            else
            {
                if (previous_wall)
                    console::ResetConsoleColor();
                previous_wall = false;
            }
                
            std::cout << c;
        }
        std::cout << std::endl;
    }
    console::ResetConsoleColor();
}

bool Map::ValidSpace(const Point &p)
{
    char c = this->m_map.at(p.Y()).at(p.X());
    switch(c)
    {
        case ' ':
            return true;
        default:
            return false;
    }
}