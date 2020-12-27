#include "ExoSkeleton.h"

int ExoSkeleton::attack() const {
    return damageRange.getValue();
}

void ExoSkeleton::print() const {
    std::cout << "ExoSkeleton " << getName() << std::endl;
    std::cout << "Level " << level << std::endl;
    std::cout << "Health " << getHealth() << std::endl;
    std::cout << "Damage range: ";
    damageRange.print();
    std::cout << "Defence " << defence << " Dodge " << dodge << std::endl;
}
