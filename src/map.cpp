#include "../include/engine/map.h"


Map::Map() {};
Map::~Map() {};

void Map::TileSet(const char* Texturefile, Vector2 size, Vector2 rows_col)
{
    int inc = 0;

    for(int y=0;y<rows_col.y;y++)
    {
        for(int x=0;x<rows_col.x;x++)
        {
            struct tile newTile;

            newTile.source.x = x*(size.x/rows_col.x);
            newTile.source.y = y*(size.y/rows_col.y);
            newTile.source.width = (size.x/rows_col.x);
            newTile.source.height = (size.y/rows_col.y);

            //Creating Hash and Adding tile to tiles
            tiles.insert({inc, newTile});
            inc++;
        }
    }

   
    
    for(int layer=0;layer<(int)layers.size();layer++)
    {
        for(int y=0;y<(int)layers[layer].size();y++)
        {
            std::vector<Entity*> line;
            for(int x=0;x<(int)layers[layer][y].size();x++)
            {
                int index = 0;
                index = std::stoi(layers[layer][y][x]);
                if(index != -1)
                {
                    Entity* tile;
                    tile = new Entity();
                    tile->init(Texturefile,{0,0}, size, 3);

                    tile->origin.x = 0;
                    tile->origin.y = 0;

                    tile->source.x = tiles[index].source.x;
                    tile->source.y = tiles[index].source.y;
                    tile->source.width = (tiles[index].source.width);
                    tile->source.height = (tiles[index].source.height);

                    tile->dest.width = (tiles[index].source.width) * 3;
                    tile->dest.height = (tiles[index].source.height) * 3;

                    tile->position.x = (x*(size.x/rows_col.x)*3);
                    tile->position.y = (y*(size.y/rows_col.y)*3);

                    line.push_back(tile);
            
                }
            }
            map.push_back(line);
        }
    }
}

void Map::AddLayer(const char* file)
{

    std::vector<std::vector<std::string>> layer;

    std::ifstream fin;
    fin.open(file);

    if(fin.fail())
    {
        std::cout << "Could not read file " << file;
    }

    
    std::string line;
    while(std::getline(fin, line))
    {


        std::vector<std::string> Aline;
        std::istringstream ss(line);

        while(ss)
        {
            std::string value;
            if(!std::getline(ss, value, ','))
            {
                break;
            }

            Aline.push_back(value);
        }

        layer.push_back(Aline);
        std::cout << std::endl;
    }

    
    layers.push_back(layer);
}   


void Map::Render()
{
    for(std::vector<Entity*> L : map)
    {
        for(Entity* e : L)
        {
            e->render();
        }
    }

}

void Map::Update()
{
     for(std::vector<Entity*> L : map)
    {
        for(Entity* e : L)
        {
            e->update();
        }
    }
}