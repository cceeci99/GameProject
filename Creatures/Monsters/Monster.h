#include <utility>

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

    void print() const override{
        std::cout << getName();
        std::cout << "Level " << level << " Health " << getHealth();
        std::cout << "Damage Range ";
        damageRange.print();
        std::cout << " Defence " << defence << " Dodge " << dodge << std::endl;
    }
};

#endif //GAMEPROJECT_MONSTER_H
