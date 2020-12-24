#include <iostream>
#include "Hero.h"

#ifndef GAMEPROJECT_WARRIOR_H
#define GAMEPROJECT_WARRIOR_H


class Warrior: public Hero {

public:

    explicit Warrior(const std::string& name): Hero(name, WARRIOR_STRENGTH, DEFAULT_DEXTERITY, WARRIOR_AGILITY){}

    ~Warrior() override = default;

    void levelUp() override {
        level++;
        experience = START_XP;

        strength += INCREASE_WARRIOR_STRENGTH;
        dexterity += INCREASE_DEFAULT_DEXTERITY;
        agility += INCREASE_WARRIOR_AGILITY;
    }

    void print() const override{
        std::cout << "Warrior " << getName() << " level " << level;
        std::cout << " Health " << getHealth() << " Mana " << getMana() << " Money " << getMoney();
        std::cout << " Strength " << strength << " Dexterity " << dexterity << " Agility " << agility << std::endl;
    }

};


#endif //GAMEPROJECT_WARRIOR_H
