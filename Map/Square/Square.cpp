#include "Square.h"

int Square::getX() const {
    return x;
}

int Square::getY() const {
    return y;
}

SquareType Square::getType() const {
    return type;
}

HeroSquad *Square::getSquad() const {
    return squad;
}

void Square::setSquad(HeroSquad *heroSquad) {
    squad = heroSquad;
}