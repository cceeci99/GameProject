#include "Spell.h"


void Spell::printDamage() const {
    damageRange.print();
}

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

int Spell::getDuration() const {
    return duration;
}

EffectType Spell::getEffectType() const {
    return type;
}

int Spell::getDamage() const {
    return damageRange.getValue();
}

int Spell::getMaxDamage() const {
    return damageRange.getMax();
}