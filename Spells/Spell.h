
#ifndef GAMEPROJECT_SPELL_H
#define GAMEPROJECT_SPELL_H

#include "../Range.h"

enum EffectType{reduce_damage, reduce_defence, reduce_dodge};

class Spell {

private:
    const std::string name;
    const int price;
    const int requiredLevel;
    const int manaRequired;

    Range damageRange;
    int duration;

    EffectType type;

public:

    Spell(std::string name, int price, int level, int mana, Range range, int duration, EffectType type)
    :name(std::move(name)), price(price), requiredLevel(level), manaRequired(mana), damageRange(range), duration(duration), type(type){};

    virtual ~Spell() = default;

    void printDamage() const;

    virtual void print() const = 0;
    virtual int getEffect() const = 0;

    EffectType getEffectType() const;

    std::string getName() const;

    int getPrice() const;
    int getRequiredLevel() const;
    int getManaRequired() const;
    int getDuration() const;
    int getMaxDamage() const;

    int cast() const;

};


#endif //GAMEPROJECT_SPELL_H