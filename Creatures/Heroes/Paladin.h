#include "Hero.h"

#ifndef GAMEPROJECT_PALADIN_H
#define GAMEPROJECT_PALADIN_H


class Paladin: public Hero {
public:

    explicit Paladin(const std::string& name): Hero(name, PALADIN_STRENGTH, PALADIN_DEXTERITY, DEFAULT_AGILITY){};
    ~Paladin() override = default;

    void levelUp() override{
        level++;
        experience = START_XP;

        strength += INCREASE_PALADIN_STRENGTH;
        dexterity += INCREASE_PALADIN_DEXTERITY;
        agility += INCREASE_DEFAULT_AGILITY;
    }

    void print() const override{
        std::cout << "Paladin: " << getName() << std::endl;
        std::cout << "Level " << level << std::endl;
        std::cout << "Money: " << getMoney() << std::endl;
        std::cout << "Health: " << getHealth() << std::endl;
        std::cout << "Mana: " << getMana() << std::endl;
        std::cout << "Attributes:" << "Strength:" << strength << " Dexterity:" << dexterity << " Agility:" << agility << std::endl;
    }
};


#endif //GAMEPROJECT_PALADIN_H
