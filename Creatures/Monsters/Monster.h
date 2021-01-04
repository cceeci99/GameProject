#include "../LivingCreature.h"
#include "../../Range.h"

 
#ifndef GAMEPROJECT_MONSTER_H
#define GAMEPROJECT_MONSTER_H

enum Monstertype{dragon=1, exoskeleton=2, spirit=3};

class Monster: public LivingCreature {

protected:
    Range damageRange;
    int defence;
    int dodge;

public:

    Monster(const std::string& name, int level, int health, Range range, int defence, int dodge)
    :LivingCreature(name, level, health), damageRange(range), defence(defence), dodge(dodge){}

    ~Monster() override = default;

    int getDefence() const;

    int getDodge() const;

    virtual int attack() const = 0;

    void print() const override = 0;

    void regeneration() override{
        if (health != 0){
            health += 15/100*health;
        }
    }

};

#endif //GAMEPROJECT_MONSTER_H