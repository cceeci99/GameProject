#include <iostream>
#include <vector>

#include "../LivingCreature.h"
#include "HERO_ATTRIBUTES.h"

#include "../../Items/Item.h"
#include "../../Items/Weapon.h"
#include "../../Spells/Spell.h"

#ifndef GAMEPROJECT_HERO_H
#define GAMEPROJECT_HERO_H


class Hero: public LivingCreature {
private:
    int mana;
    int money;

protected:
    int experience;
    int strength;
    int dexterity;
    int agility;

public:
    Hero(const std::string& name, int newStrength, int newDexterity, int newAgility): LivingCreature(name, START_LEVEL, START_HP){
        mana = START_MP;
        money = START_MONEY;
        experience = START_XP;

        strength = newStrength;
        dexterity = newDexterity;
        agility = newAgility;
    }

    ~Hero() override = default;

    int getMana() const;

    int getMoney() const;

    void addExperience(int xp);

    void print() const override = 0;

    virtual void levelUp() = 0;
};



#endif //GAMEPROJECT_HERO_H