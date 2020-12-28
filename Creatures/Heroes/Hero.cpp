#include "Hero.h"

int Hero::getMana() const {
    return mana;
}

int Hero::getMoney() const {
    return money;
}

void Hero::addExperience(int xp) {
    experience += xp;

    if ( experience >= 100 ) {
        levelUp();
    }
}
