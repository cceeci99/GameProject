#include "Monster.h"

#ifndef GAMEPROJECT_SPIRIT_H
#define GAMEPROJECT_SPIRIT_H


class Spirit: public Monster {
public:
    Spirit(const std::string& name, int level, int health, Range range, int defence, int dodge):Monster(name, level, health, range, defence, dodge){};
    ~Spirit() override = default;

    int attack() const override;
    void print() const override;

};


#endif //GAMEPROJECT_SPIRIT_H
