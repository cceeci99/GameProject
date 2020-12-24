#include "Spell.h"

#ifndef GAMEPROJECT_ICESPELL_H
#define GAMEPROJECT_ICESPELL_H


class IceSpell: public Spell {
private:
    const int reduceDamage;

public:
    IceSpell(const std::string& name, int price, int level, int mana, Range range, int reduce):Spell(name, price, level, mana, range), reduceDamage(reduce){};
    ~IceSpell() override = default;

    void print() const override{
        std::cout << "Ice Spell: " << getName() << " with damage range ";
        getDamageRange();
        std::cout << " and reduceDamage " << reduceDamage << std::endl;
    }
    int getEffect() const override{
        return reduceDamage;
    }
};


#endif //GAMEPROJECT_ICESPELL_H
