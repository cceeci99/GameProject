
#ifndef GAMEPROJECT_FIRESPELL_H
#define GAMEPROJECT_FIRESPELL_H

#include "Spell.h"

#define FIRE_DURATION 1


class FireSpell: public Spell {

private:
    const int reduceDefence;

public:

    FireSpell(const std::string& name, int price, int level, int mana, Range range, int reduce)
    :Spell(name, price, level, mana, range, FIRE_DURATION, reduce_defence), reduceDefence(reduce){};

    ~FireSpell() override = default;

    void print() const override;

    int getEffect() const override;
};


#endif //GAMEPROJECT_FIRESPELL_H