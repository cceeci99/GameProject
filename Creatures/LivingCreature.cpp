#include "LivingCreature.h"

LivingCreature::LivingCreature(std::string name, int health, int level) : name(std::move(name)), health(health), level(level){}

LivingCreature::~LivingCreature() = default;

std::string LivingCreature::getName() const {
    return name;
}

int LivingCreature::getHealth() const {
    return health;
}

int LivingCreature::getLevel() const {
    return level;
}

