#include "Monster.h"

Monster::Monster(const std::string &name, int level, int health, Range range, int defence, int dodge) : LivingCreature(name, level, health), damageRange(range), defence(defence), dodge(dodge){}

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

