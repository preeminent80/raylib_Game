#include "../include/engine/map.h"


Map::Map() {};
Map::~Map() {};

void Map::TileSet(const char* Texturefile, Vector2 size, Vector2 rows_col)
{

    for(int y=0;y<rows_col.y;y++)
    {
        for(int x=0;x<rows_col.x;x++)
        {
            Entity* tile;
            tile = new Entity();
            tile->init(Texturefile,{0,0}, {size.x, size.y}, 0.1f);

            //Init tiles and slices each once
            tile->source.x = x*(size.x/rows_col.x);
            tile->source.y = y*(size.y/rows_col.y);
            tile->source.width = (size.x/rows_col.x);
            tile->source.height = (size.y/rows_col.y);

            //Creating Hash and Adding tile to map
            tileset.insert({(y*40)+x, *tile});
        }
    }

    int index = 0;
    Entity* Temptile;
    for(int layer=0;layer<layers.size();layer++)
    {
        std::vector<Entity*> re;
        for(int row=0;row<layers[layer].size();row++)
        {
            for(int e=0;e<layers[layer][row].size();e++)
            {
                index = std::stoi(layers[layer][row][e]);
                if(index != -1)
                {
                    Temptile = &tileset[index];
                    
                    Temptile->position.x = e*(size.x/rows_col.x);
                    Temptile->position.y = row*(size.y/rows_col.y);



                    re.push_back(Temptile); 
                } 
            }
            std::cout<< std::endl;
        }
        reLayers.push_back(re);
    }
}

void Map::AddLayer(const char* file)
{

    std::vector<std::vector<std::string>> layer;
    layers.push_back(layer);

    std::ifstream fin;
    fin.open(file);

    if(fin.fail())
    {
        std::cout << "Could not read file " << file;
    }

    
    std::string line;
    std::vector<std::string> Aline;
    while(!fin.eof())
    {
        std::getline(fin, line);
        std::istringstream ss(line);

        while (std::getline(ss, line, ',')) {
            Aline.push_back(line);
        }
        layer.push_back(Aline);
    }

    for(std::vector<std::string> row : layer)
    {
        for(std::string e : row)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
}   


void Map::Render()
{
    for(std::vector<Entity*> L : reLayers)
    {
        for(Entity* e : L)
        {
            e->render();
        }
    }
}

void Map::Update()
{
    for(std::vector<Entity*> L : reLayers)
    {
        for(Entity* e : L)
        {
            e->update();
        }
    }
}