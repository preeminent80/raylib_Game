#pragma once
#include "Game.h"
#include <iostream>
#include <unordered_map>

class Entity
{
public:

    //Textures and Source And Dest Rects And SpriteSheet and Frame Data
    Texture2D texture;
    Rectangle spriteSheetData;
    Rectangle frameData;
    Rectangle source;
    Rectangle dest;

    //Animation
    std::unordered_map<const char*, Vector2> animations;
    int current_frame = 0;
    float timer = 0.0f;
    bool isPlayingAnim = false;
    bool Looped = false;
    int Frames = 0;

    unsigned int scale = 1;
    unsigned int rotation = 0;
    Vector2 position;
    Vector2 origin = {0,0};

    Entity(); 
    ~Entity();

    void init(const char* texturePath, Vector2 pos, Vector2 size, int scale); // x is width and y is height
    void init(const char* texturePath, Vector2 pos, Vector2 rows_col, Vector2 size, int scale); // x is witdh and y is height - x is col and y is rows
    void AddAnimation(const char* name, Vector2 SectionOfSpriteSheet);//Sprite Sheet Need For This To Work -- Look For Over Loaded Contructur To Create Sprite Sheet. Split It Into Sections(Not Indivdual Sprites)
    void RunAnim(const char* name, bool looped, int frames);
    void StopAnim();
    void SelectSpriteFromSheet(int x, int y);
    void PlayAnim();

    virtual void update();
    void render();
};

//Add collision