#include "FireSpell.h"

void FireSpell::print() const {
    std::cout << "Fire Spell: " << getName() << " Effect: ReduceDefence by: " << reduceDefence << " DamageRange: ";
    printDamage();
}

int FireSpell::getEffect() const {
    return reduceDefence;
}