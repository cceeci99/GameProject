
#ifndef GAMEPROJECT_SPIRIT_H
#define GAMEPROJECT_SPIRIT_H

#include "Monster.h"


class Spirit: public Monster {

public:

    Spirit(const std::string& name, int level) //int health, Range range, int defence, int dodge)
    :Monster(name, level, Range(DEFAULT_MIN_RANGE + (level-1)*INCREASE_DEFAULT_MIN_RANGE, DEFAULT_MAX_RANGE + (level-1)*INCREASE_DEFAULT_MAX_RANGE), DEFAULT_DEFENCE + (level-1)*INCREASE_DEFAULT_DEFENCE, SPIRIT_DODGE + (level-1)*INCREASE_SPIRIT_DODGE){};

    ~Spirit() override = default;

    void print() const override;

    int attack() const override;

};


#endif //GAMEPROJECT_SPIRIT_H
