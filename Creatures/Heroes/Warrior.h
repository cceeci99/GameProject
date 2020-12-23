#include <utility>

#include "../LivingCreature.h"
#include "Hero.h"

#ifndef GAMEPROJECT_WARRIOR_H
#define GAMEPROJECT_WARRIOR_H


class Warrior: public Hero {
public:
    explicit Warrior(const std::string& name):Hero(name, WARRIOR_STRENGTH, DEFAULT_DEXTERITY, WARRIOR_AGILITY){}

    Warrior(const std::string& name, int newStrength, int newDexterity, int newAgility):Hero(name, newStrength, newDexterity, newAgility){}

    ~Warrior() override = default;

    void levelUp() override {
        level++;
        experience = START_XP;

        strength += INCREASE_WARRIOR_STRENGTH;
        dexterity += INCREASE_DEFAULT_DEXTERITY;
        agility += INCREASE_WARRIOR_AGILITY;
    }

};


#endif //GAMEPROJECT_WARRIOR_H
