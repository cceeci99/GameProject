#include <iostream>
#include <utility>

#ifndef GAMEPROJECT_LIVINGCREATURE_H
#define GAMEPROJECT_LIVINGCREATURE_H


class LivingCreature {

private:
    const std::string name;
    int health;

protected:
    int level;

public:
    LivingCreature(std::string name, int level, int health): name(std::move(name)), level(level), health(health){}

    virtual ~LivingCreature() = default;

    std::string getName() const;

    int getHealth() const;

    int getLevel() const;

    virtual void print() const = 0;

};


#endif //GAMEPROJECT_LIVINGCREATURE_H