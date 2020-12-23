#include <utility>

#include "../LivingCreature.h"
#include "../../Range.h"

#ifndef GAMEPROJECT_MONSTER_H
#define GAMEPROJECT_MONSTER_H


class Monster: public LivingCreature {
protected:
    Range damageRange;
    int defence{};
    int dodge{};


public:
    Monster(const std::string& name, Range range): LivingCreature(name), damageRange(range){};
    ~Monster() override = default;


};

#endif //GAMEPROJECT_MONSTER_H
