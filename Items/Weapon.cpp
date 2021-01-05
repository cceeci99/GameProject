#include "Weapon.h"


void Weapon::print() const {
    std::cout << "Weapon: " << getName() << ", Damage: " << damage << ", Type: " << weaponType << std::endl;
}

int Weapon::getAttribute() const {
    return damage;
}

bool Weapon::isOneHanded() const {
    return oneHanded;
}