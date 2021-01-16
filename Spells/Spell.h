
#ifndef GAMEPROJECT_SPELL_H
#define GAMEPROJECT_SPELL_H

#include "../Range/Range.h"

//enumeration for the effect type of the spell used on monsters
enum EffectType{reduce_damage, reduce_defence, reduce_dodge};


class Spell {

private:
    //each spell has it's name, price required level and mana
    const std::string name;
    const int price;
    const int requiredLevel;
    const int manaRequired;

    //each spell has effect type, a damage range and some duration
    EffectType type;
    Range damageRange;
    int duration;


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

    int getDamage() const;
    int getMaxDamage() const;

};


#endif //GAMEPROJECT_SPELL_H