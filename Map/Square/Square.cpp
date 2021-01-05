#include "Square.h"

SquareType Square::getType() const {
    return type;
}

int Square::getX() const {
    return x;
}

int Square::getY() const {
    return y;
}

HeroSquad *Square::getSquad() const {
    return squad;
}

void Square::setSquad(HeroSquad *heroSquad) {
    squad = heroSquad;
}
