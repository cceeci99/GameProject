#include "Spell.h"

#include <utility>

#ifndef GAMEPROJECT_LIGHTINGSPELL_H
#define GAMEPROJECT_LIGHTINGSPELL_H


class LightingSpell: public Spell {

private:
    const int reduceDodge;

public:

    LightingSpell(const std::string& name, int price, int level, int mana, Range range, int reduce)
    : Spell(name, price, level, mana, range, 2), reduceDodge(reduce){};

    ~LightingSpell() override = default;

    void print() const override;

    int getEffect() const override;

};


#endif //GAMEPROJECT_LIGHTINGSPELL_H
