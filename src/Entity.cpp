#include "../include/engine/Entity.h"


int reverse = 0;



Entity::Entity()
{

}

Entity::~Entity()
{
  
}


void Entity::init(const char* texturePath, Vector2 pos, Vector2 size, float Scale)
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




void Entity::update()
{
    dest.x = position.x;
    dest.y = position.y;

}

void Entity::render()
{
    DrawTexturePro(texture,source,dest,origin,rotation,WHITE);
}

animation Entity::AddAnim(const char* texturePath, std::string  name, Vector2 SectionOfSpriteSheet, Vector2 rows_col, Vector2 size, int frames)
{   
    struct animation newAnim;

    if(texturePath == "base")
    {
        newAnim.texture = texture;
    }
    else{
            newAnim.texture = LoadTexture(texturePath);
    }
    

    newAnim.source.x = rows_col.x;
    newAnim.source.y = rows_col.y;
    newAnim.source.height = size.y/rows_col.y;
    newAnim.source.width = size.x /rows_col.x;

    source.x = SectionOfSpriteSheet.x*newAnim.source.width;
    source.y = SectionOfSpriteSheet.y*newAnim.source.height;
    source.width = newAnim.source.width;
    source.height = newAnim.source.height;

    dest.height = newAnim.source.height * scale;
    dest.width = newAnim.source.width * scale;

    origin.x = dest.height/2;
    origin.y = dest.width/2;

    newAnim.current_frame = 0;
    newAnim.timer = 0.0f;
    newAnim.Looped = false;
    newAnim.isPlayingAnim = false;
    newAnim.Frames = frames;

    animations.insert({name, newAnim});

    const Rectangle temp = animations[name].source;


    animations[name].source.x = animations[name].Frames;
    animations[name].source.y =  SectionOfSpriteSheet.y; // single frames not 2d spritesheet thus why y stays 0
    animations[name].source.height = temp.height; // gets the animated sprite height
    animations[name].source.width = temp.width /animations[name].source.x; // gets the animated sprite width 

    

    return newAnim;
}

void Entity::RunAnim(std::string name, bool looped)
{   
    if(animations.find(name) != animations.end())
    {
        animations[name].Looped = looped;

        animations[name].isPlayingAnim = true;
        currentAnimation = name;
    } else 
    {
        std::cout << "\nAnimation-> " << name << " <-Does Not Exist" << std::endl;
    }
}


void Entity::PlayAnim()
{
    if(!currentAnimation.empty()){
        struct animation anim = animations[currentAnimation];
       
        if(anim.isPlayingAnim)
        {
            animations[currentAnimation].timer += GetFrameTime();
            if(anim.timer>= 0.2f)
            {   
                if(animations[currentAnimation].Looped == false)
                {
            
                    animations[currentAnimation].timer = 0.0f;
                    animations[currentAnimation].current_frame += 1;
                    animations[currentAnimation].current_frame = animations[currentAnimation].current_frame % animations[currentAnimation].Frames;
                    if(animations[currentAnimation].current_frame == 0)
                    {
                        reverse++;
                    }
                    if(reverse == 2)
                    {
                        StopAnim();
                    }
                }
                else{
                    animations[currentAnimation].timer = 0.0f;
                    animations[currentAnimation].current_frame += 1;
                }
            }

            if(animations[currentAnimation].Looped == true)
            {
                animations[currentAnimation].current_frame = animations[currentAnimation].current_frame % animations[currentAnimation].Frames;
            }
            

            source.x = animations[currentAnimation].current_frame*animations[currentAnimation].source.width; // Changes the frame in the sheet
            
            source.y = animations[currentAnimation].source.y* animations[currentAnimation].source.height; // y stays same since we are animation a single line animation #note y is the section we chose
            source.width =  animations[currentAnimation].source.width; // width of the new animated sprite
            source.height =  animations[currentAnimation].source.height;// height of the new animated sprite

            dest.height =  animations[currentAnimation].source.height * scale;// fixes the scale and height of the new animated sprite on screen
            dest.width =  animations[currentAnimation].source.width * scale; // same here

            origin.x = dest.height/2; // fixes orgin
            origin.y = dest.width/2; // same here

        }
    }
}

void Entity::StopAnim()
{
    if(!currentAnimation.empty())
    {
        animations[currentAnimation].isPlayingAnim = false;
    }

}

