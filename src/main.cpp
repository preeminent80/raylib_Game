#include "../include/engine/Game.h"
Game* game;

int main(void)
{
    game = new Game();

    game->init(400,800,"Window",60);

    while(!game->notRunning())
    {
        game->update();
        game->render();
    }

    game->Close();

    return 0;
}