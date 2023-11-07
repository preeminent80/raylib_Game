#pragma once
#include "Game.h"
#include "Entity.h"

class Player : public Entity
{
public:
    Vector2 velocity = {0,0};
    int speed = 3;

    

    void update() override
    {
       
        Entity::update();

        position.x += velocity.x * speed;
        position.y += velocity.y * speed;

        //Keyboard Input
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D)) {
            if (IsKeyDown(KEY_W)) {
                velocity.y = -1;
            }
            if (IsKeyDown(KEY_A)) {
                velocity.x = -1;
            }
            if (IsKeyDown(KEY_S)) {
                velocity.y = 1;
            }
            if (IsKeyDown(KEY_D)) {
                velocity.x = 1;
            }
        } else {
            if (IsKeyUp(KEY_W)) {
                velocity.y = 0;
            }
            if (IsKeyUp(KEY_A)) {
                velocity.x = 0;
            }
            if (IsKeyUp(KEY_S)) {
                velocity.y = 0;
            }
            if (IsKeyUp(KEY_D)) {
                velocity.x = 0;
            }
        }

    } 
    
};