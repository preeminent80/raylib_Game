#include "../raylib.h"
#include "Entity.h"
#include <iostream>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct tile
{
    Rectangle source;
};

class Map
{
public:

    Map();
    ~Map();
    void TileSet(const char* file, Vector2 size, Vector2 rows_col);
    void AddLayer(const char* file);
    void Render();
    void Update();
    std::unordered_map<int, struct tile> tiles;
    std::vector<std::vector<std::vector<std::string>>> layers;
    std::vector<std::vector<Entity*>> map;
private:
};
