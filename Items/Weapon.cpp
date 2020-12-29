#include "Weapon.h"

bool Weapon::isOneHanded() const {
    return oneHanded;
}

void Weapon::print() const {
    std::cout << "Weapon: " << getName() << ", Damage: " << damage << ", Type: " << weaponType << std::endl;
}

int Weapon::getAttribute() const {
    return damage;
}