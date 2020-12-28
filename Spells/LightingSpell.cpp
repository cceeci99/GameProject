#include "LightingSpell.h"

void LightingSpell::print() const {
    std::cout << "Lighting Spell: " << getName() << " Reduce Dodge effect by: " << reduceDodge << " Damage range ";
    printDamage();
}

int LightingSpell::getEffect() const {
    return reduceDodge;
}
