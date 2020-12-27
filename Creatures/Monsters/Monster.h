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
    Monster(const std::string& name, int level, int health, Range range, int defence, int dodge);
    ~Monster() override;

    int getDefence() const;
    int getDodge() const;
    void printDamageRange() const;

    virtual int attack() const = 0;
    void print() const override = 0;

};

#endif //GAMEPROJECT_MONSTER_H