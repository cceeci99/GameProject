#include "Monster.h"

#ifndef GAMEPROJECT_EXOSKELETON_H
#define GAMEPROJECT_EXOSKELETON_H


class ExoSkeleton: public Monster {

public:

    ExoSkeleton(const std::string& name, int level, int health, Range range, int defence, int dodge)
    :Monster(name, level, health, range, defence, dodge){};

    ~ExoSkeleton() override = default;

    void print() const override;

    int attack() const override;

};


#endif //GAMEPROJECT_EXOSKELETON_H
