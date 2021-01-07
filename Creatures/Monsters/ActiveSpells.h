
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


    void activate(EffectType type, int duration){
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

    void disable(EffectType type){
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

    void reduceRound() {
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

    bool mustDisable(EffectType type){
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

};


#endif //GAMEPROJECT_ALLSPELLSDURATION_H