#include "Item.h"

Item::~Item() = default;

std::string Item::getName() const {
    return name;
}

int Item::getPrice() const {
    return price;
}

int Item::getRequiredLevel() const {
    return requiredLevel;
}
