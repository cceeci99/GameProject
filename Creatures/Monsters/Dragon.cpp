#include "Dragon.h"

Dragon::Dragon(const std::string &name, int health, int level, Range range, int defence, int dodge) : Monster(name, health, level, range, defence, dodge){}

int Dragon::attack() const {
    return damageRange.getValue();
}

void Dragon::print() const {
    std::cout << "Dragon " << getName() << std::endl;
    std::cout << "Level " << level << std::endl;
    std::cout << "Health " << getHealth() << std::endl;
    std::cout << "Damage range: ";
    damageRange.print();
    std::cout << "Defence " << defence << " Dodge " << dodge << std::endl;
}
