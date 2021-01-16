#include "Monster.h"


bool Monster::avoidAttack() const {
    int r = (int)random() % 100 +1;

    return (r <= dodge);
}


void Monster::reduceHealth(int reduce) {
    if (reduce <= defence)
        return;

    health = health - (reduce-defence);

    if (health < 0)
    {
        health = 0;
    }
}


void Monster::reduceDamage(int reduce) {
    damageRange.reduceRange(reduce);
}


void Monster::reduceDefence(int reduce) {
    defence -= reduce;

    if (defence < 0)
    {
        defence = 0;
    }
}


void Monster::reduceDodge(int reduce) {
    dodge -= reduce;

    if (dodge < 0)
    {
        dodge = 0;
    }
}


bool Monster::dead() const {
    return health==0;
}


void Monster::regenerate() {

    if (health != 0)
    {
        health += (int) (health*0.1);

        if (health >= 1000)
        {
            health = 1000;
        }
    }
}


void Monster::activateSpell(EffectType type, int duration) {
    spells.activate(type, duration);
}


void Monster::reduceSpellsDuration() {
    spells.reduceDuration();
}


void Monster::checkExpiredSpells() {

    if (spells.expired(reduce_defence))
    {
        spells.disable(reduce_defence);
        defence = INIT_DEFENCE;
    }

    if (spells.expired(reduce_damage))
    {
        spells.disable(reduce_damage);
        damageRange = INIT_DAMAGE;
    }

    if (spells.expired(reduce_dodge))
    {
        spells.disable(reduce_dodge);
        dodge = INIT_DODGE;
    }
}