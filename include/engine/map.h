#include "../raylib.h"
#include "Entity.h"
#include <iostream>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Map
{
public:
    Map();
    ~Map();
    void TileSet(const char* file, Vector2 size, Vector2 rows_col);
    void AddLayer(const char* file);
    void SetTileMap();
    void Render();
    void Update();
    std::unordered_map<int, Entity> tileset;
    std::vector<std::vector<std::vector<std::string>>> layers;
    std::vector<std::vector<Entity*>> reLayers;
private:
};