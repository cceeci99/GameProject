
#ifndef GAMEPROJECT_LIGHTINGSPELL_H
#define GAMEPROJECT_LIGHTINGSPELL_H

#include "Spell.h"

#define LIGHTING_DURATION 2


class LightingSpell: public Spell {

private:
    const int reduceDodge;

public:

    LightingSpell(const std::string& name, int price, int level, int mana, Range range, int reduce)
    : Spell(name, price, level, mana, range, LIGHTING_DURATION, reduce_dodge), reduceDodge(reduce){};

    ~LightingSpell() override = default;

    void print() const override;

    int getEffect() const override;

};


#endif //GAMEPROJECT_LIGHTINGSPELL_H
