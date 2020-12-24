#include "Hero.h"

#ifndef GAMEPROJECT_SORCERER_H
#define GAMEPROJECT_SORCERER_H


class Sorcerer: public Hero {
public:

    explicit Sorcerer(const std::string& name): Hero(name, DEFAULT_STRENGTH, SORCERER_DEXTERITY, SORCERER_AGILITY){}
    ~Sorcerer() override = default;


    void levelUp() override{
        level++;
        experience = START_XP;

        strength += INCREASE_DEFAULT_STRENGTH;
        dexterity += INCREASE_SORCERER_DEXTERITY;
        agility += INCREASE_SORCERER_AGILITY;
    }

    void print() const override{
        std::cout << "Sorcerer: " << getName() << std::endl;
        std::cout << "Level " << level << std::endl;
        std::cout << "Money: " << getMoney() << std::endl;
        std::cout << "Health: " << getHealth() << std::endl;
        std::cout << "Mana: " << getMana() << std::endl;
        std::cout << "Attributes:" << "Strength:" << strength << " Dexterity:" << dexterity << " Agility:" << agility << std::endl;
    }

};


#endif //GAMEPROJECT_SORCERER_H
