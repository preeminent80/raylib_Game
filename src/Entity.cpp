#include "../include/engine/Entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{
  
}


void Entity::init(const char* texturePath, Vector2 pos, Vector2 size, int Scale)
{
    texture = LoadTexture(texturePath);
    position.x = (int) pos.x;
    position.y = (int) pos.y;
    dest.height = size.y * Scale;
    dest.width = size.x * Scale;

    scale = Scale;

    source.x = 0;
    source.y = 0;
    source.width = size.x;
    source.height = size.y;

    origin.x = dest.height/2;
    origin.y = dest.width/2;
}

void Entity::init(const char* texturePath, Vector2 pos, Vector2 rows_col, Vector2 size, int Scale)
{
    texture = LoadTexture(texturePath);
    position.x = (int) pos.x;
    position.y = (int) pos.y;
    dest.height = size.y * Scale;
    dest.width = size.x * Scale;

    scale = Scale;


    spriteSheetData.x = rows_col.x;
    spriteSheetData.y = rows_col.y;
    spriteSheetData.height = size.y/rows_col.y;
    spriteSheetData.width = size.x /rows_col.x;

    

    source.x = 0;
    source.y = 0;
    source.width =  size.x;
    source.height = size.y;

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

void Entity::update()
{
    dest.x = position.x;
    dest.y = position.y;

    PlayAnim();

 
}

void Entity::render()
{
    DrawTexturePro(texture,source,dest,origin,rotation,WHITE);
}

void Entity::AddAnimation(const char* name, Vector2 SectionOfSpriteSheet)
{
    animations.insert({name, SectionOfSpriteSheet});
}

void Entity::RunAnim(const char* name, bool looped, int frames)
{
    if(animations.find(name) != animations.end())
    {
        
        isPlayingAnim = true;
        Looped = looped;
        Frames = frames;

        SelectSpriteFromSheet((int) animations[name].x, (int) animations[name].y);
        std::cout << animations[name].x <<", "<<animations[name].y;

        frameData.x = frames;
        frameData.y =  animations[name].y; // single frames not 2d spritesheet thus why y stays 0
        frameData.height = spriteSheetData.height; // gets the animated sprite height
        frameData.width = spriteSheetData.width /frameData.x; // gets the animated sprite width 

        std::cout << "\nLoaded Animation: " << name << ", " << "Looped = " << looped << std::endl;

    } else 
    {
        std::cout << "\nAnimation-> " << name << " <-Does Not Exist" << std::endl;
    }
}

void Entity::PlayAnim()
{

   
    if(isPlayingAnim)
    {

        timer += GetFrameTime();
        if(timer>= 0.2f)
        {
            timer = 0.0f;
            current_frame += 1;
            if(Looped == false)
            {
                if(current_frame < Frames)
                {
                    current_frame += 1;
                } else{
                    current_frame-=1;
                    if(current_frame == 0)
                    {
                        StopAnim();
                    }
                }   
            }
        }

        if(Looped == true)
        {
            current_frame = current_frame % Frames;
        }


        source.x = current_frame*frameData.width; // Changes the frame in the sheet
        
        source.y = frameData.y*frameData.height; // y stays same since we are animation a single line animation #note y is the section we chose
        source.width = frameData.width; // width of the new animated sprite
        source.height = frameData.height;// height of the new animated sprite

        dest.height = frameData.height * scale;// fixes the scale and height of the new animated sprite on screen
        dest.width = frameData.width * scale; // same here

        origin.x = dest.height/2; // fixes orgin
        origin.y = dest.width/2; // same here

        

        // SelectSpriteFromSheet((int) animations[name].x, (int) animations[name].y);  changes the animation back to the selected section > MIGHT WANNA FIX LATER
    }
}

void Entity::StopAnim()
{
    isPlayingAnim = false;
}