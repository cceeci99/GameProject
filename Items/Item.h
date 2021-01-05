
#ifndef GAMEPROJECT_ITEM_H
#define GAMEPROJECT_ITEM_H

#include <iostream>


enum ItemType{armor, weapon, potion};

class Item {

private:
    const std::string name;
    const int price;
    const int requiredLevel;
    ItemType type;

public:

    Item(std::string  name, int price, int level, ItemType type)
    :name(std::move(name)), price(price), requiredLevel(level), type(type){};

    virtual ~Item() = default;

    virtual void print() const = 0;

    virtual int getAttribute() const = 0;

    std::string getName() const;

    ItemType getType() const;

    int getPrice() const;
    int getRequiredLevel() const;

};


#endif //GAMEPROJECT_ITEM_H