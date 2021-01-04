#include "Monster.h"

int Monster::getDefence() const {
    return defence;
}

int Monster::getDodge() const {
    return dodge;
}

void Monster::regeneration() {
    if (health != 0){
        health += 15/100*health;
    }
}
