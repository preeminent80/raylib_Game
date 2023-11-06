#include "../include/engine/Entity.h"

Entity::Entity(const char* texturePath, int posx, int posy, int widthOfEntireImage, int heightOfEntireImage, int Scale)
{
    texture = LoadTexture(texturePath);
    position.x = (int) posx;
    position.y = (int) posy;
    dest.height = widthOfEntireImage * scale;
    dest.width = heightOfEntireImage * scale;

    scale = Scale;

    source.x = 0;
    source.y = 0;
    source.width = widthOfEntireImage;
    source.height = heightOfEntireImage;

    origin.x = dest.height/2;
    origin.y = dest.width/2;
}

Entity::Entity(const char* texturePath, int posx, int posy, int rows, int columns, int height, int width, int Scale)
{
    texture = LoadTexture(texturePath);
    position.x = (int) posx;
    position.y = (int) posy;

    scale = Scale;

    dest.height = height * scale;
    dest.width = width * scale;

    spriteSheetData.x = columns;
    spriteSheetData.y = rows;
    spriteSheetData.height = height/rows;
    spriteSheetData.width = width /columns;

    

    source.x = 0;
    source.y = 0;
    source.width =  width;
    source.height = height;

    origin.x = dest.height/2;
    origin.y = dest.width/2;
}

void Entity::SelectSpriteFromSheet(int x, int y)
{
    source.x = x*spriteSheetData.width;
    source.y = y*spriteSheetData.height;
    source.width = spriteSheetData.width;
    source.height = spriteSheetData.height;

    dest.height = spriteSheetData.height * scale;
    dest.width = spriteSheetData.width * scale;

    origin.x = dest.height/2;
    origin.y = dest.width/2;
}
Entity::~Entity()
{
  
}

void Entity::setRotation(unsigned int degree)
{
    rotation = degree;
}
unsigned int Entity::getRotation()
{
    return rotation;
}
void Entity::update()
{
    dest.x = position.x;
    dest.y = position.y;

    //Testing Entity Class
    setRotation(45 * GetTime());
    
}

void Entity::render()
{
    DrawTexturePro(texture,source,dest,origin,rotation,WHITE);
}