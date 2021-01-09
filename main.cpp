#include <iostream>

#include "Game.h"

int main() {
    srandom(time(nullptr));

    Game* game = new Game();

    game->createMarket();

    game->createMap(8);

    game->play();

    delete game;

    return 0;

}