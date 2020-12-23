#include <utility>

#include "Hero.h"

#ifndef GAMEPROJECT_SORCERER_H
#define GAMEPROJECT_SORCERER_H


class Sorcerer: public Hero {
public:
    explicit Sorcerer(const std::string& name): Hero(name, DEFAULT_STRENGTH, SORCERER_DEXTERITY, SORCERER_AGILITY){}

    Sorcerer(const std::string& name, int newStrength, int newDexterity, int newAgility):Hero(name, newStrength, newDexterity, newAgility){};

    ~Sorcerer() override = default;

    void levelUp() override{
        level++;
        experience = START_XP;

        strength += INCREASE_DEFAULT_STRENGTH;
        dexterity += INCREASE_SORCERER_DEXTERITY;
        agility += INCREASE_SORCERER_AGILITY;

    }
};


#endif //GAMEPROJECT_SORCERER_H
