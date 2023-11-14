#include "../include/engine/Game.h"
#include "../include/engine/Entity.h"
#include "../include/engine/Player.h"
#include "../include/engine/map.h"
#include <assert.h>
#include <iostream>
#include <unordered_map> 

#define FPS_POS GetScreenToWorld2D({10,10}, newPLayer->camera)


//Player Dec
Player* newPLayer;

//Map dec
Map* map;


Game::Game(int windowHeight, int windowWidth, const char* windowName, int targetFps, int argc, char* argv[])
{
    assert(!GetWindowHandle()); //If Assertion Window Already Open
    InitWindow(windowWidth, windowHeight, windowName);
    SetTargetFPS(targetFps);

    //Testing Player Class
    newPLayer = new Player();
    newPLayer->init("res/PlayerSprites/Walk.png", {300,225},{64,128}, 3.0f); 

    //Map Init Under Dev
    map = new Map();
    map->AddLayer("res/Map/Ground.csv");
    map->AddLayer("res/Map/Enviroment.csv");
    map->TileSet("res/Map/Overworld.png", {640, 576}, {640/16,576/16}); 

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
    BeginMode2D(newPLayer->camera);
        Update();
        Render();
    EndMode2D();
    EndDrawing();
}
void Game::Update()
{
    //Map
    map->Update();

    //Player
    newPLayer->update();
}
void Game::Render()
{
    ClearBackground(RAYWHITE);
    map->Render();
    DrawText(TextFormat("FPS: %i", GetFPS()), FPS_POS.x,FPS_POS.y, 10, BLACK);
    newPLayer->render();

}


