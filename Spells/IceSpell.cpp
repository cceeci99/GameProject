#include "IceSpell.h"

void IceSpell::print() const {
    std::cout << "Ice Spell: " << getName() << " Effect Reduce Damage by: " << reduceDamage << " Damage range ";
    printDamage();
}

int IceSpell::getEffect() const {
    return reduceDamage;
}
