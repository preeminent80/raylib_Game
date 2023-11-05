#pragma once
#include "raylib.h"


class Game 
{
private:

public:

    Game();
    ~Game();
    void init(int windowHeight, int windowWidth, const char* windowName, int targetFps);
    bool notRunning();
    void Close();
    void update();
    void render();
};