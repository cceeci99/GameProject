
#ifndef GAMEPROJECT_DRAGON_H
#define GAMEPROJECT_DRAGON_H

#include "Monster.h"


class Dragon: public Monster {

public:

    Dragon(const std::string& name, int level)//{ // int health, Range range, int defence, int dodge)
    :Monster(name, level, Range(DRAGON_MIN_RANGE + (level-1)*INCREASE_DRAGON_MIN_RANGE, DRAGON_MAX_RANGE + (level-1)*INCREASE_DRAGON_MAX_RANGE), DEFAULT_DEFENCE + (level-1)*INCREASE_DEFAULT_DEFENCE, DEFAULT_DODGE + (level-1)*INCREASE_DEFAULT_DODGE){}

    ~Dragon() override = default;

    void print() const override;

    int attack() const override;

};


#endif //GAMEPROJECT_DRAGON_H
