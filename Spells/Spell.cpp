#include "Spell.h"

Spell::~Spell() = default;

std::string Spell::getName() const {
    return name;
}

int Spell::getPrice() const {
    return price;
}

int Spell::getRequiredLevel() const {
    return requiredLevel;
}

int Spell::getManaRequired() const {
    return manaRequired;
}

void Spell::printDamage() const {
    damageRange.print();
}

int Spell::cast() const {
    return damageRange.getValue();
}
