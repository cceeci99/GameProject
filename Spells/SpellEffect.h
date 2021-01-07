
#ifndef GAMEPROJECT_SPELLDURATION_H
#define GAMEPROJECT_SPELLDURATION_H

#include "Spell.h"


class SpellEffect {

private:

    EffectType type;
    int durationRounds;
    bool active;

public:

    SpellEffect(EffectType type)
    :type(type), durationRounds(0), active(false) {};

    ~SpellEffect() = default;

    bool isActive() const{
        return active;
    }

    void activate(int duration){
        active = true;
        durationRounds = duration;
    }

    void reduceRound(){
        durationRounds--;
    }

    bool mustDisable(){
        return (active && durationRounds == 0);
    }

    void disable(){
        active = false;
        durationRounds = 0;
    }

};


#endif //GAMEPROJECT_SPELLDURATION_H