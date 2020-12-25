#include "Monster.h"

Monster::Monster(const std::string &name, int health, int level, Range range, int defence, int dodge) : LivingCreature(name, health, level), damageRange(range), defence(defence), dodge(dodge){}

Monster::~Monster() = default;

int Monster::getDefence() const {
    return defence;
}

int Monster::getDodge() const {
    return dodge;
}

void Monster::printDamageRange() const {
    damageRange.print();
}

