#include "LightingSpell.h"


void LightingSpell::print() const {
    std::cout << "Lighting Spell: " << getName() << " Effect: ReduceDodge by: " << reduceDodge << " DamageRange: ";
    printDamage();
}

int LightingSpell::getEffect() const {
    return reduceDodge;
}
