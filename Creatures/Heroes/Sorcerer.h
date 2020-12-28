#include "Hero.h"

#ifndef GAMEPROJECT_SORCERER_H
#define GAMEPROJECT_SORCERER_H


class Sorcerer: public Hero {
public:
    explicit Sorcerer(const std::string& name): Hero(name, DEFAULT_STRENGTH, SORCERER_DEXTERITY, SORCERER_AGILITY){}

    ~Sorcerer() override = default;

    void print() const override;

    void levelUp() override;

};


#endif //GAMEPROJECT_SORCERER_H
