#ifndef GAMEPROJECT_ITEM_H
#define GAMEPROJECT_ITEM_H

#include <iostream>
#include <utility>

enum Items{armor, weapon, potion};

class Item {

private:
    const std::string name;
    const int price;
    const int requiredLevel;
    Items type;

public:

    Item(std::string  name, int price, int level, Items type)
    :name(std::move(name)), price(price), requiredLevel(level), type(type){};

    virtual ~Item() = default;

    Items getType() const;

    std::string getName() const;

    int getPrice() const;

    int getRequiredLevel() const;

    virtual void print() const = 0;

    virtual int getAttribute() const = 0;

};


#endif //GAMEPROJECT_ITEM_H