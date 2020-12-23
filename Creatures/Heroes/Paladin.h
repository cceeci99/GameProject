#include <utility>

#include "Hero.h"

#ifndef GAMEPROJECT_PALADIN_H
#define GAMEPROJECT_PALADIN_H


class Paladin: public Hero {
public:
    explicit Paladin(const std::string& name): Hero(name, PALADIN_STRENGTH, PALADIN_DEXTERITY, DEFAULT_AGILITY){};\

    Paladin(const std::string& name, int newStrength, int newDexterity, int newAgility): Hero(name, newStrength, newDexterity, newAgility){}

    ~Paladin() override = default;

    void levelUp() override{
        level++;
        experience = START_XP;

        strength += INCREASE_PALADIN_STRENGTH;
        dexterity += INCREASE_PALADIN_DEXTERITY;
        agility += INCREASE_DEFAULT_AGILITY
    }
};


#endif //GAMEPROJECT_PALADIN_H
