#include "Potion.h"

void Potion::print() const {
    std::cout << "Potion: " << getName() << ", Increase " << attributeType << " by " << enhancement << std::endl;
}

int Potion::getAttribute() const {
    return enhancement;
}

Attribute Potion::getAttributeType() const {
    return attribute;
}