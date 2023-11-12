#pragma once
#include "Game.h"
#include <iostream>
#include <unordered_map>

struct animation
{
    Texture2D texture;
    Rectangle source;
    int current_frame;
    float timer = 0.0f;
    bool isPlayingAnim ;
    bool Looped;
    int Frames;
};

class Entity
{
public:

    //Textures and Source And Dest Rects And SpriteSheet and Frame Data.
    Texture2D texture;
    Rectangle source;
    Rectangle dest;

    //Animation
    std::unordered_map<std::string, struct animation> animations;
    std::string currentAnimation;


    float scale = 1;
    unsigned int rotation = 0;
    Vector2 position;
    Vector2 origin = {0,0};

    Entity(); 
    ~Entity();

    virtual void init(const char* texturePath, Vector2 pos, Vector2 size, float Scale); 
    animation AddAnim(const char* texturePath,  std::string name, Vector2 SectionOfSpriteSheet, Vector2 rows_col, Vector2 size, int frames);
    void RunAnim(std::string name, bool looped);
    void StopAnim();
    void PlayAnim();

    virtual void update();
    virtual void render();
};

