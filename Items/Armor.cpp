#include "Armor.h"

void Armor::print() const {
    std::cout << "Armor: " << getName() << ", Defence: " << defence << std::endl;
}

int Armor::getAttribute() const {
    return defence;
}