#include "Sorcerer.h"

void Sorcerer::print() const {
    std::cout << "Sorcerer: " << getName() << std::endl;
    std::cout << "Level " << level << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Mana: " << getMana() << std::endl;
    std::cout << "Money: " << getMoney() << std::endl;
    std::cout << "Attributes: " << "Strength:" << strength << " Dexterity:" << dexterity << " Agility:" << agility << std::endl;
}

void Sorcerer::levelUp() {
    level++;
    experience = START_XP;

    strength += INCREASE_DEFAULT_STRENGTH;
    dexterity += INCREASE_SORCERER_DEXTERITY;
    agility += INCREASE_SORCERER_AGILITY;
}
