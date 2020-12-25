#include "Monster.h"


#ifndef GAMEPROJECT_DRAGON_H
#define GAMEPROJECT_DRAGON_H


class Dragon: public Monster {

public:
    Dragon(const std::string& name, int health, int level, Range range, int defence, int dodge);
    ~Dragon() override = default;

    int attack() const override;
    void print() const override;

};


#endif //GAMEPROJECT_DRAGON_H
