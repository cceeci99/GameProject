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
    LivingCreature(std::string name, int health, int level): name(std::move(name)), health(health), level(level){};
    virtual ~LivingCreature() = 0;

    std::string getName() const{
        return name;
    }
    int getHealth() const{
        return health;
    }
    int getLevel() const{
        return level;
    }

    virtual void print() const = 0;
    virtual void levelUp() = 0;
};


#endif //GAMEPROJECT_LIVINGCREATURE_H
