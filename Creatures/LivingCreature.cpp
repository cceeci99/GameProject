#include "LivingCreature.h"

LivingCreature::LivingCreature(std::string name, int level, int health) : name(std::move(name)), level(level), health(health){}

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

