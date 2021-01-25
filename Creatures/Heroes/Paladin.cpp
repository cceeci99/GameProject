#include "Paladin.h"


void Paladin::print() const {
    std::cout << "Paladin: " << getName() << std::endl;
    std::cout << "Level " << level << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Mana: " << mana << std::endl;
    std::cout << "Attributes: " << "\tStrength: " << strength << "\tDexterity: " << dexterity << "\tAgility: " << agility << std::endl;
}

void Paladin::levelUp() {
    level++;
    health = MAX_HP;
    mana = MAX_MP;
    experience = START_XP;

    strength += INCREASE_PALADIN_STRENGTH;
    dexterity += INCREASE_PALADIN_DEXTERITY;
    agility += INCREASE_DEFAULT_AGILITY;
}