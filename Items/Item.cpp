#include "Item.h"


ItemType Item::getType() const {
    return type;
}

std::string Item::getName() const {
    return name;
}

int Item::getPrice() const {
    return price;
}

int Item::getRequiredLevel() const {
    return requiredLevel;
}