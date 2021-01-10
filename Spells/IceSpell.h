
#ifndef GAMEPROJECT_ICESPELL_H
#define GAMEPROJECT_ICESPELL_H

#include "Spell.h"

#define ICE_DURATION 3


class IceSpell: public Spell {

private:
    const int reduceDamage;

public:

    IceSpell(const std::string& name, int price, int level, int mana, Range range, int reduce)
    :Spell(name, price, level, mana, range, ICE_DURATION, reduce_damage), reduceDamage(reduce){};

    ~IceSpell() override = default;

    void print() const override;

    int getEffect() const override;
};


#endif //GAMEPROJECT_ICESPELL_H