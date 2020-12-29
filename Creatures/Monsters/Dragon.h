#include "Monster.h"


#ifndef GAMEPROJECT_DRAGON_H
#define GAMEPROJECT_DRAGON_H


class Dragon: public Monster {

public:

    Dragon(const std::string& name, int level, int health, Range range, int defence, int dodge)
    :Monster(name, level, health, range, defence, dodge){}

    ~Dragon() override = default;

    void print() const override;

    int attack() const override;

};


#endif //GAMEPROJECT_DRAGON_H
