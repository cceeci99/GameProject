
#ifndef GAMEPROJECT_ITEM_H
#define GAMEPROJECT_ITEM_H

#include <iostream>


//enumeration for the type of item, it is given by the constructors of subclasses
enum ItemType{armor, weapon, potion};


class Item {

private:
    //each item has it's name, price and required level
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

    ItemType getType() const;

    std::string getName() const;

    int getPrice() const;

    int getRequiredLevel() const;

};


#endif //GAMEPROJECT_ITEM_H