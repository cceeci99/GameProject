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

void LivingCreature::setHealth(int newHealth) {
    health = newHealth;
}

