#include "Paladin.h"

void Paladin::print() const {
    std::cout << "Paladin: " << getName() << std::endl;
    std::cout << "Level " << level << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Mana: " << getMana() << std::endl;
    std::cout << "Money: " << getMoney() << std::endl;
    std::cout << "Attributes: " << "Strength:" << strength << " Dexterity:" << dexterity << " Agility:" << agility << std::endl;
}

void Paladin::levelUp() {
    level++;
    experience = START_XP;

    strength += INCREASE_PALADIN_STRENGTH;
    dexterity += INCREASE_PALADIN_DEXTERITY;
    agility += INCREASE_DEFAULT_AGILITY;
}
