#pragma once
#include "Game.h"
#include "Entity.h"


class Player : public Entity
{
public:
    Camera2D camera;
    Vector2 velocity = {0,0};
    int speed = 3;
    std::string dir = "down";



    void init(const char* texturePath, Vector2 pos, Vector2 size,float Scale) override
    {
        Entity::init(texturePath, pos, size, Scale);

        //Anims
        AddAnim("res/PlayerSprites/Walk.png","Walk_W", {0,2}, {1,4}, {64, 128}, 4); 
        AddAnim("res/PlayerSprites/Walk.png", "Walk_A", {0,3}, {1,4}, {64, 128}, 4);
        AddAnim("res/PlayerSprites/Walk.png", "Walk_S", {0,0}, {1,4}, {64, 128}, 4); 
        AddAnim("res/PlayerSprites/Walk.png", "Walk_D", {0,1}, {1,4}, {64, 128}, 4); 
        
        //Faces
        AddAnim("res/PlayerSprites/Walk.png","Walk_WI", {0,2}, {4,4}, {64, 128}, 1); 
        AddAnim("res/PlayerSprites/Walk.png", "Walk_AI", {0,3}, {4,4}, {64, 128}, 1);
        AddAnim("res/PlayerSprites/Walk.png", "Walk_SI", {0,0}, {4,4}, {64, 128}, 1); 
        AddAnim("res/PlayerSprites/Walk.png", "Walk_DI", {0,1}, {4,4}, {64, 128}, 1); 

        camera.offset = {GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
        camera.target = position;
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;
    }

    void update() override
    {
       
        Entity::update();
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
        
        

        //Inputs
        //W input

        PlayAnim();

        if(IsKeyPressed(KEY_W))
        {
            velocity.y = -1;
            RunAnim("Walk_W", true);
            dir = "up";

        }
        //A input
        if(IsKeyPressed(KEY_A))
        {
            velocity.x = -1;
            RunAnim("Walk_A", true);
            dir = "left";
        }
        //S input
        if(IsKeyPressed(KEY_S))
        {
            velocity.y = 1;
            RunAnim("Walk_S", true);
            dir = "down";
        }
        //D input
        if(IsKeyPressed(KEY_D))
        {
            velocity.x = 1;
            RunAnim("Walk_D", true);
            dir = "right";
        }
       


        if(IsKeyReleased(KEY_W) || IsKeyReleased(KEY_S))
        {
            velocity.y = 0;
            if(dir == "down")
            {
                RunAnim("Walk_SI", false);
            }
            if(dir == "up")
            {
                RunAnim("Walk_WI", false);
            }
        }

        if(IsKeyReleased(KEY_A) || IsKeyReleased(KEY_D))
        {
            velocity.x = 0;
            if(dir == "right")
            {
                RunAnim("Walk_DI", false);
            }
            if(dir == "left")
            {
                RunAnim("Walk_AI", false);
            }
        }

      
    } 
    
    void render() override
    {
        Entity::render();
        
        //Camera
        camera.target = position;
    }

};