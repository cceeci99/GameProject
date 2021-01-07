#include "Monster.h"

void Monster::reduceHealth(int reduce) {
    health = health - (reduce-defence);
}

void Monster::reduceDamage(int reduce) {
    damageRange.reduceRange(reduce);
}

void Monster::reduceDefence(int reduce) {
    defence -= reduce;
}

void Monster::reduceDodge(int reduce) {
    dodge -= reduce;
}

void Monster::regeneration() {
    if (health != 0){
        health += 15/100*health;
    }
}

bool Monster::avoidAttack() const {
    int r = (int)random() % 100 +1;

    return (r <= dodge);
}