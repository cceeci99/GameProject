
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

    std::string getName() const;

    int getHealth() const;

    int getLevel() const;

    void setHealth(int newHealth){
        health = newHealth;
    }

    virtual void print() const = 0;

    virtual void regeneration() = 0;

};


#endif //GAMEPROJECT_LIVINGCREATURE_H