#include "Weapon.h"

bool Weapon::isOneHanded() const {
    return oneHanded;
}

void Weapon::print() const {
    std::cout << "Weapon: " << getName() << " Damage: " << damage << " Type: " << type << std::endl;
}

int Weapon::getAttribute() const {
    return damage;
}