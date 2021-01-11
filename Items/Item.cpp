#include "Item.h"

std::string Item::getName() const {
    return name;
}

ItemType Item::getType() const {
    return type;
}

int Item::getPrice() const {
    return price;
}

int Item::getRequiredLevel() const {
    return requiredLevel;
}