#include "Sorcerer.h"

void Sorcerer::print() const {
    std::cout << "Sorcerer: " << getName() << std::endl;
    std::cout << "Level " << level << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Mana: " << mana << std::endl;
    std::cout << "Attributes: " << "\tStrength: " << strength << "\tDexterity: " << dexterity << "\tAgility: " << agility << std::endl;
}

void Sorcerer::levelUp() {
    level++;
    experience = START_XP;

    strength += INCREASE_DEFAULT_STRENGTH;
    dexterity += INCREASE_SORCERER_DEXTERITY;
    agility += INCREASE_SORCERER_AGILITY;
}