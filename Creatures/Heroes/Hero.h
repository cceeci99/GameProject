#include <utility>

#include "../LivingCreature.h"
#include "HERO_ATTRIBUTES.h"

#ifndef GAMEPROJECT_HERO_H
#define GAMEPROJECT_HERO_H


class Hero: public LivingCreature {
private:
    int mana = START_MP;
    int money = START_MONEY;

protected:
    int experience = START_XP;
    int strength{};
    int dexterity{};
    int agility{};

public:
    explicit Hero(std::string name):LivingCreature(std::move(name)){}

    Hero(const std::string& name, int newStrength, int newDexterity, int newAgility) : LivingCreature(name), strength(newStrength), dexterity(newDexterity), agility(newAgility){}

    ~Hero() override = default;

    void addExperience(int xp){
        experience += xp;

        if ( experience >= 100 )
            levelUp();
    }

    void levelUp() override = 0;
};


#endif //GAMEPROJECT_HERO_H
