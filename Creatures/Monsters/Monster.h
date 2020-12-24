#include "../LivingCreature.h"
#include "../../Range.h"

#ifndef GAMEPROJECT_MONSTER_H
#define GAMEPROJECT_MONSTER_H


class Monster: public LivingCreature {
protected:
    Range damageRange;
    int defence;
    int dodge;

public:
    Monster(const std::string& name, int health, int level, Range range, int defence, int dodge): LivingCreature(name, health, level), damageRange(range), defence(defence), dodge(dodge){};
    ~Monster() override = 0;

    int getDefence() const{
        return defence;
    }
    int getDodge() const{
        return dodge;
    }
    void getDamageRange() const{
        damageRange.print();
    }
    virtual void print() = 0;
};

#endif //GAMEPROJECT_MONSTER_H
