#include "ExoSkeleton.h"


void ExoSkeleton::print() const {
    std::cout << "ExoSkeleton: " << getName() << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Defence: " << defence << std::endl;
    std::cout << "Dodge: " << dodge << std::endl;
    std::cout << "Damage range: ";
    damageRange.print();
}

int ExoSkeleton::attack() const {
    return damageRange.getValue();
}