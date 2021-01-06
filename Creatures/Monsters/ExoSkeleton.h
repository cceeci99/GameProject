
#ifndef GAMEPROJECT_EXOSKELETON_H
#define GAMEPROJECT_EXOSKELETON_H

#include "Monster.h"


class ExoSkeleton: public Monster {

public:

    ExoSkeleton(const std::string& name, int level)
    :Monster(name, level, Range(DEFAULT_MIN_RANGE + (level-1)*INCREASE_DEFAULT_MAX_RANGE, DEFAULT_MAX_RANGE + (level-1)*INCREASE_DEFAULT_MAX_RANGE), EXOSKELETON_DEFENCE + (level-1)*INCREASE_EXOSKELETON_DEFENCE, DEFAULT_DODGE + (level-1)*INCREASE_DEFAULT_DODGE){};

    ~ExoSkeleton() override = default;

    void print() const override;

    int attack() const override;

};


#endif //GAMEPROJECT_EXOSKELETON_H