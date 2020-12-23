#include "Spell.h"

#ifndef GAMEPROJECT_FIRESPELL_H
#define GAMEPROJECT_FIRESPELL_H


class FireSpell: public Spell {
private:
    const int reduceDefence;

public:
    FireSpell(const std::string& name, int price, int level, int mana, Range range, int reduce): Spell(name, price, level, mana, range), reduceDefence(reduce){};
    ~FireSpell() override = default;

    int use() const override{
        return reduceDefence;
    }
};


#endif //GAMEPROJECT_FIRESPELL_H
