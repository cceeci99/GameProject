#include "IceSpell.h"

void IceSpell::print() const {
    std::cout << "Ice Spell: " << getName() << " Effect: ReduceDamage by: " << reduceDamage << " DamageRange: ";
    printDamage();
}

int IceSpell::getEffect() const {
    return reduceDamage;
}