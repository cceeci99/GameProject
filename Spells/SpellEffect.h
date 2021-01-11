
#ifndef GAMEPROJECT_SPELLDURATION_H
#define GAMEPROJECT_SPELLDURATION_H

#include "Spell.h"


class SpellEffect {

private:

    EffectType type;
    int durationRounds;
    bool active;

public:

    explicit SpellEffect(EffectType type)
    :type(type), durationRounds(0), active(false) {};

    ~SpellEffect() = default;

    bool isActive() const;

    void activate(int duration);

    void disable();

    void reduceDuration();

    bool expired() const;

};


#endif //GAMEPROJECT_SPELLDURATION_H