#include "Monster.h"

void Monster::reduceHealth(int reduce) {
    if ( reduce <= defence )
        return;

    health = health - (reduce-defence);

    if ( health < 0 ) {
        health = 0;
    }
}

bool Monster::dead() const {
    return health==0;
}

void Monster::reduceDamage(int reduce) {
    damageRange.reduceRange(reduce);
}

void Monster::reduceDefence(int reduce) {
    defence -= reduce;

    if ( defence < 0 ) {
        defence = 0;
    }
}

void Monster::reduceDodge(int reduce) {
    dodge -= reduce;
    if ( dodge < 0 ) {
        dodge = 0;
    }
}

void Monster::regeneration() {
    if (health != 0)
    {
        health += 15/100*health;

        if (health >= 1000) {
            health = 1000;
        }
    }
}

bool Monster::avoidAttack() const {
    int r = (int)random() % 100 +1;

    return (r <= dodge);
}

void Monster::activateSpell(EffectType type, int duration) {
    spells.activate(type, duration);
}

void Monster::reduceSpellsRound() {
    spells.reduceRound();
}

void Monster::checkExpiredSpells() {
    if ( spells.mustDisable(reduce_defence) )
    {
        spells.disable(reduce_defence);
        defence = INIT_DEFENCE;
    }

    if ( spells.mustDisable(reduce_damage) )
    {
        spells.disable(reduce_damage);
        damageRange = INIT_DAMAGE;
    }

    if ( spells.mustDisable(reduce_dodge) )
    {
        spells.disable(reduce_dodge);
        dodge = INIT_DODGE;
    }
}


