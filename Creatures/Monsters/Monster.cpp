#include "Monster.h"

void Monster::reduceHealth(int reduce) {
    if ( reduce <= defence )
        return;

    health = health - (reduce-defence);

    if ( health < 0 ) {
        health = 0;
    }
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
//        health += 15/100*health;
        health += 50;
        if (health >= 1000)
            health = 1000;
    }
}

bool Monster::avoidAttack() const {
    int r = (int)random() % 100 +1;

    return (r <= dodge);
}