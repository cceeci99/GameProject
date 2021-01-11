#include "ActiveSpells.h"

void ActiveSpells::activate(EffectType type, int duration) {

    if (type == reduce_defence)
    {
        fire.activate(duration);
    }
    else if (type == reduce_damage)
    {
        ice.activate(duration);
    }
    else
    {
        lighting.activate(duration);
    }
}


void ActiveSpells::disable(EffectType type) {

    if (type == reduce_defence)
    {
        fire.disable();
    }
    else if(type == reduce_damage)
    {
        ice.disable();
    }
    else
    {
        lighting.disable();
    }
}


void ActiveSpells::reduceDuration() {

    //check for spell witch is active and reduce it's duration
    if (fire.isActive())
    {
        fire.reduceDuration();
    }

    if (ice.isActive())
    {
        ice.reduceDuration();
    }

    if (lighting.isActive())
    {
        lighting.reduceDuration();
    }
}


bool ActiveSpells::expired(EffectType type) {

    if (type == reduce_defence)
    {
        return fire.expired();
    }
    else if (type == reduce_damage)
    {
        return ice.expired();
    }
    else
    {
        return lighting.expired();
    }
}