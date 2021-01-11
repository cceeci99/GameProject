
#ifndef GAMEPROJECT_PALADIN_H
#define GAMEPROJECT_PALADIN_H

#include "Hero.h"


class Paladin: public Hero {

public:

    explicit Paladin(const std::string& name)
    :Hero(name, PALADIN_STRENGTH, PALADIN_DEXTERITY, DEFAULT_AGILITY){};

    ~Paladin() override = default;

    void print() const override;

    void levelUp() override;

};


#endif //GAMEPROJECT_PALADIN_H