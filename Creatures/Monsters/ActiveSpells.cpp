#include "ActiveSpells.h"

void ActiveSpells::activate(EffectType type, int duration) {
    if (type == reduce_defence) {
        fire.activate(duration);
    }
    else if (type == reduce_damage) {
        ice.activate(duration);
    }
    else {
        lighting.activate(duration);
    }
}

void ActiveSpells::disable(EffectType type) {
    if (type == reduce_defence) {
        fire.disable();
    }
    else if(type == reduce_damage) {
        ice.disable();
    }
    else {
        lighting.disable();
    }
}

void ActiveSpells::reduceRound() {
    if (fire.isActive()) {
        fire.reduceRound();
    }

    if (ice.isActive()) {
        ice.reduceRound();
    }

    if (lighting.isActive()) {
        lighting.reduceRound();
    }
}

bool ActiveSpells::mustDisable(EffectType type) {
    if (type == reduce_defence){
        return fire.mustDisable();
    }
    else if (type == reduce_damage){
        return ice.mustDisable();
    }
    else{
        return lighting.mustDisable();
    }
}
