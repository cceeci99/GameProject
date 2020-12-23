#include "Spell.h"

#ifndef GAMEPROJECT_ICESPELL_H
#define GAMEPROJECT_ICESPELL_H


class IceSpell {
private:
    const int reduceDamage;

public:
    IceSpell(const std::string& name, double price, int level, int mana, int low, int high, int reduce):Spell(name, price, level, mana, low, high), reduceDamage(reduce){};
    ~IceSpell() override = default;


};


#endif //GAMEPROJECT_ICESPELL_H
