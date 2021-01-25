#include "LivingCreature.h"


std::string LivingCreature::getName() const {
    return name;
}

int LivingCreature::getHealth() const {
    return health;
}

int LivingCreature::getLevel() const {
    return level;
}

bool LivingCreature::dead() const {
    return health == 0;
}