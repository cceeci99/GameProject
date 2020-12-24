#include "Spell.h"

#include <utility>

#ifndef GAMEPROJECT_LIGHTINGSPELL_H
#define GAMEPROJECT_LIGHTINGSPELL_H


class LightingSpell: public Spell {
private:
    const int reduceDodge;

public:
    LightingSpell(const std::string& name, int price, int level, int mana, Range range, int reduce): Spell(name, price, level, mana, range), reduceDodge(reduce){};
    ~LightingSpell() override = default;

    void print() const override{
        std::cout << "Lighting Spell " <<getName() << " with damage range ";
        getDamageRange();
        std::cout << " and reduce dodge " << reduceDodge << std::endl;
    }

    int getEffect() const override{
        return reduceDodge;
    }
};


#endif //GAMEPROJECT_LIGHTINGSPELL_H
