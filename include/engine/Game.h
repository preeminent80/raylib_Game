#pragma once
#include "../raylib.h"


class Game 
{
private:

public:

    Game(int windowHeight, int windowWidth, const char* windowName, int targetFps);
    ~Game() noexcept;

    bool GameShouldClose();
    void Tick();
    void Update();
    void Render();
};