#include <iostream>

#include "Game.h"

int main() {

    srandom(time(nullptr));

    Game game;

    game.play();

    return 0;
}