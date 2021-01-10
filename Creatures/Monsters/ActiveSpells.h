
#ifndef GAMEPROJECT_ALLSPELLSDURATION_H
#define GAMEPROJECT_ALLSPELLSDURATION_H

#include "../../Spells/SpellEffect.h"


class ActiveSpells {

private:
    SpellEffect fire;
    SpellEffect ice;
    SpellEffect lighting;

public:

    ActiveSpells()
    :fire(reduce_defence), ice(reduce_damage), lighting(reduce_dodge){}

    ~ActiveSpells() = default;

    void activate(EffectType type, int duration);

    void disable(EffectType type);

    void reduceRound();

    bool expired(EffectType type);

};


#endif //GAMEPROJECT_ALLSPELLSDURATION_H