#include "FireSpell.h"

void FireSpell::print() const {
    std::cout << "Fire Spell: " << getName() << " Effect Reduce Defence by: " << reduceDefence << " Damage range: ";
    printDamage();
}

int FireSpell::getEffect() const {
    return reduceDefence;
}
