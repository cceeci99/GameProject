#include "Spirit.h"

int Spirit::attack() const {
    return damageRange.getValue();
}

void Spirit::print() const {
    std::cout << "Spirit " << getName() << std::endl;
    std::cout << "Level " << level << std::endl;
    std::cout << "Health " << getHealth() << std::endl;
    std::cout << "Damage range: ";
    damageRange.print();
    std::cout << "Defence " << defence << " Dodge " << dodge << std::endl;
}

