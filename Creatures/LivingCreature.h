#include <iostream>
#include <utility>

#include "LIVING_ATTRIBUTES.h"

#ifndef GAMEPROJECT_LIVINGCREATURE_H
#define GAMEPROJECT_LIVINGCREATURE_H


class LivingCreature {
private:
    const std::string name;
    double health = START_HP;

protected:
    int level = START_LEVEL;

public:
    explicit LivingCreature(std::string name): name(std::move(name)){};
    virtual ~LivingCreature() = 0;

    std::string getName() const{
        return name;
    }

    void reduceHealth(double damage){
        health -= damage;
    }

    virtual void levelUp() = 0;
};


#endif //GAMEPROJECT_LIVINGCREATURE_H
