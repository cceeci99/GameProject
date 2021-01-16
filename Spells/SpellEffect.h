
#ifndef GAMEPROJECT_SPELLDURATION_H
#define GAMEPROJECT_SPELLDURATION_H

#include "Spell.h"

//this class keeps the information for the effect of a spell,
//it's type(reduce damage,defence or dodge), it's durationRounds initialized with zero, and boolean status (activated or disabled)

class SpellEffect {

private:

    EffectType type;
    int durationRounds;
    bool active;

public:

    SpellEffect(EffectType type)
    :type(type), durationRounds(0), active(false) {};

    ~SpellEffect() = default;

    bool isActive() const;

    void activate(int duration);

    void disable();

    void reduceDuration();

    bool expired() const;

};


#endif //GAMEPROJECT_SPELLDURATION_H