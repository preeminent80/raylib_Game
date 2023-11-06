#include "Game.h"

class Entity
{
private:
    Texture2D texture;
    Rectangle spriteSheetData;
    Rectangle source;
    Rectangle dest;
    unsigned int rotation = 0;
    unsigned int scale = 1;
public:
    Vector2 position;
    Vector2 origin = {0,0};

    Entity(const char* texturePath, int posx, int posy, int width, int height, int scale);
    Entity(const char* texturePath, int posx, int poxy, int rows, int columns, int height, int width, int scale);
    ~Entity();

    void SelectSpriteFromSheet(int x, int y);
    void setRotation(unsigned int degree);
    unsigned int getRotation();
    

    void update();
    void render();
};