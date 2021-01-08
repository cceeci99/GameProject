#include <iostream>

#include "Game.h"

int main() {
    srandom(time(nullptr));

    Game* game = new Game();

    game->createMarket();

    game->createMap(5);

    game->play();

    delete game;

    return 0;

}