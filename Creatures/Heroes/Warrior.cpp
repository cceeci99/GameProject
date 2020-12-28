#include "Warrior.h"

void Warrior::print() const {
    std::cout << "Warrior: " << getName() << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Mana: " << getMana() << std::endl;
    std::cout << "Money: " << getMoney() << std::endl;
    std::cout << "Attributes: " << "Strength:" << strength << " Dexterity:" << dexterity << " Agility:" << agility << std::endl;
}

void Warrior::levelUp() {
    level++;
    experience = START_XP;

    strength += INCREASE_WARRIOR_STRENGTH;
    dexterity += INCREASE_DEFAULT_DEXTERITY;
    agility += INCREASE_WARRIOR_AGILITY;
}
