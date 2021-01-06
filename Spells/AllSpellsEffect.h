#include "SpellEffect.h"

#ifndef GAMEPROJECT_ALLSPELLSDURATION_H
#define GAMEPROJECT_ALLSPELLSDURATION_H

class AllSpellsEffect {
    private:
        SpellEffect* fireSpellEffect;
        SpellEffect* iceSpellEffect;
        SpellEffect* lightingSpellEffect;

    public:
        AllSpellsEffect(){
            fireSpellEffect = new SpellEffect(reduce_defence);
            iceSpellEffect = new SpellEffect(reduce_damage);
            lightingSpellEffect = new SpellEffect(reduce_dodge);
        }

        void activate(EffectType type, int duration){
            if(type == reduce_defence)
                fireSpellEffect->activate(duration);
            else if(type == reduce_damage)
                iceSpellEffect->activate(duration);
            else
                lightingSpellEffect->activate(duration);
        }

        void reduceRound(){
            if(fireSpellEffect->isActivated())
                fireSpellEffect->reduceRound();
            
            if(iceSpellEffect->isActivated())
                iceSpellEffect->reduceRound();
            
            if(lightingSpellEffect->isActivated())
                lightingSpellEffect->reduceRound();
        }

        void disable(EffectType type){

            if(type == reduce_damage){
                iceSpellEffect->disable()
            }
            else if(type == reduce_defence){
                fireSpellEffect->disable();
            }
            else{
                lightingSpellEffect->disable();
            }
        }
        
        bool mustDisable(EffectType type){
            if(type == reduce_damage){
                return iceSpellEffect->mustDisable();
            }
            else if(type == reduce_defence){
                return fireSpellEffect->mustDisable();
            }
            else{
                return lightingSpellEffect->mustDisable();
            }
        }
};

#endif //GAMEPROJECT_ALLSPELLSDURATION_H