#include "Spell.h"

#ifndef GAMEPROJECT_SPELLDURATION_H
#define GAMEPROJECT_SPELLDURATION_H

class SpellEffect {
    private:
        int durationRounds;
        bool active;
        EffectType type;
    public:
        SpellEffect(EffectType t) : durationRounds(0), active(false), type(t){}

        void reduceRound(){
            durationRounds--;
        }

        void activate(int duration){
            durationRounds = duration;
            active = true;            
        }

        void disable(){
            active = false;
            durationRounds = 0;
        }

        bool mustDisable(){
            return (active && durationRounds == 0)
        }
};

#endif //GAMEPROJECT_SPELLDURATION_H