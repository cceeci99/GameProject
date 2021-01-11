
#ifndef GAMEPROJECT_LIVINGCREATURE_H
#define GAMEPROJECT_LIVINGCREATURE_H

#include <iostream>


class LivingCreature {

private:
    const std::string name;

protected:
    int level;
    int health;

public:

    LivingCreature(std::string name, int level, int health)
    :name(std::move(name)), level(level), health(health){}

    virtual ~LivingCreature() = default;

    virtual void print() const = 0;

    virtual void reduceHealth(int reduce) = 0;

    virtual void regenerate() = 0;

    std::string getName() const;

    int getHealth() const;
    int getLevel() const;

};


#endif //GAMEPROJECT_LIVINGCREATURE_H