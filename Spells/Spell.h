#include <iostream>
#include <utility>

#ifndef GAMEPROJECT_SPELL_H
#define GAMEPROJECT_SPELL_H


class DamageRange{
public:
    int low;
    int high;

    DamageRange(int low, int high):low(low), high(high){};

};

class Spell {
private:
    const std::string name;
    const double price;
    const int requiredLevel{};
    const int manaRequired;
    DamageRange damageRange;

public:
    Spell(std::string name, double price, int level, int mana, int low, int high):name(std::move(name)), price(price), requiredLevel(level), manaRequired(mana), damageRange(low, high){};
    virtual ~Spell() = 0;

    std::string getName() const{
        return name;
    }
    double getPrice() const{
        return price;
    }
    int getRequiredLevel() const{
        return requiredLevel;
    }
    int getManaRequired() const{
        return manaRequired;
    }

    virtual void print() = 0;
};


#endif //GAMEPROJECT_SPELL_H
