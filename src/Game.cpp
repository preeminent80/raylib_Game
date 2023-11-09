#include "../include/engine/Game.h"
#include "../include/engine/Entity.h"
#include "../include/engine/Player.h"
#include <assert.h>
#include <iostream>
#include <unordered_map> 
Player* newPLayer;

Game::Game(int windowHeight, int windowWidth, const char* windowName, int targetFps)
{
    assert(!GetWindowHandle()); //If Assertion Window Already Open
    InitWindow(windowWidth, windowHeight, windowName);
    SetTargetFPS(targetFps);

    WaitTime(2);
    //Testing Player Class
    newPLayer = new Player();
    newPLayer->init("../res/TestAnimation.png", {300,225},{64,128}, 3); 
    newPLayer->AddAnimation("../res/TestAnimation.png","Walk_W", {0,0}, {1,4}, {64, 128});
    newPLayer->RunAnim("Walk_W", true, 4);
    
    
}
Game::~Game()   
{
    assert(GetWindowHandle()); //If Assertion Window Already Closed
    CloseWindow();
}
bool Game::GameShouldClose()
{
    return WindowShouldClose();
}
void Game::Tick()
{
    BeginDrawing();
        Update();
        Render();
    EndDrawing();
}
void Game::Update()
{
    newPLayer->update();

}
void Game::Render()
{
    ClearBackground(RAYWHITE);
    DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 10, BLACK);
    newPLayer->render();

}