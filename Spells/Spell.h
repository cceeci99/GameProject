#include <iostream>
#include <utility>

#include "../Range.h"

#ifndef GAMEPROJECT_SPELL_H
#define GAMEPROJECT_SPELL_H

class Spell {
private:
    const std::string name;
    const int price;
    const int requiredLevel;
    const int manaRequired;
    Range damageRange;

public:
    Spell(std::string name, int price, int level, int mana, Range range):name(std::move(name)), price(price), requiredLevel(level), manaRequired(mana), damageRange(range){};
    virtual ~Spell() = 0;

    std::string getName() const{
        return name;
    }
    int getPrice() const{
        return price;
    }
    int getRequiredLevel() const{
        return requiredLevel;
    }
    int getManaRequired() const{
        return manaRequired;
    }

    virtual int getEffect() const = 0;
};


#endif //GAMEPROJECT_SPELL_H
