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

map_t& Map::CreateMapFromFile(std::string file)
{
    std::ifstream map_file(file.c_str());
    std::string row_data;
    if (map_file.is_open())
    {
        while (std::getline(map_file, row_data))
        {
            std::vector<char> row;
            for (char c : row_data)
            {
                if (c == END)
                    break;
                
                row.push_back(c);
            }
            this->m_map.push_back(row);
        }
    }
    else
    {
        std::cout << "Could not open " << file << std::endl;
    }
    map_file.close();
    this->AddBorder();
    return this->m_map;
}

map_t& Map::AddBorder()
{
    //Horzontal Border
    const std::vector<char> border_h(this->Size().X(), SQUARE_WALL.ch);
    auto it = this->m_map.begin();
    it = this->m_map.insert(it, border_h);
    this->m_map.push_back(border_h);

    //Vertical Border
    for (int y = 0; y < this->Size().Y(); ++y)
    {
        auto it = this->m_map.at(y).begin();
        it = this->m_map.at(y).insert(it, SQUARE_WALL.ch);
        this->m_map.at(y).push_back(SQUARE_WALL.ch);
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
    char previous_square = ' ';
    for (int y = 0; y < size.Y(); ++y)
    {
        for (int x = 0; x < size.X(); ++x)
        {
            Point currentPoint = Point(x, y);
            char c = this->m_map.at(y).at(x);

            bool sqaure_type_found = false;
            for (square_t sqaure : SQUARE_TYPES)
            {
                if (c == sqaure.ch)
                {
                    if (x == 0 || previous_square != c)
                        console::SetConsoleColor(sqaure.color, true);
                    previous_square = c;
                    c = ' ';
                    sqaure_type_found = true;
                    break;
                }
            }
            if (!sqaure_type_found)
            {
                std::cerr << "INVALID SQUARE IN MAP: " << c << std::endl;
            }
            
            if (this->m_player.GetPosition() == currentPoint)
                c = PLAYER;

            std::cout << c;
        }
        console::ResetConsoleColor();
        std::cout << std::endl;
    }
    console::ResetConsoleColor();
}

bool Map::EncounterSpace(const Point &p)
{
    const char c = this->m_map.at(p.Y()).at(p.X());
    if (c == SQUARE_EMPTY.ch)
    {
        return true;
    }
    else if (c == SQUARE_DOOR.ch)
    {
        return true;
    }
    else if (c == SQUARE_WALL.ch)
    {
        return false;
    }
    else if (c == SQUARE_MONSTER.ch)
    {
        return false;
    }
    else
    {
        return false;
    }
}
