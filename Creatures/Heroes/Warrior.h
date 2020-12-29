#include <iostream>
#include "Hero.h"

#ifndef GAMEPROJECT_WARRIOR_H
#define GAMEPROJECT_WARRIOR_H


class Warrior: public Hero {

public:

    explicit Warrior(const std::string& name)
    :Hero(name, WARRIOR_STRENGTH, DEFAULT_DEXTERITY, WARRIOR_AGILITY){}

    ~Warrior() override = default;

    void levelUp() override;

    void print() const override;

};


#endif //GAMEPROJECT_WARRIOR_H
