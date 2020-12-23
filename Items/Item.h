#ifndef GAMEPROJECT_ITEM_H
#define GAMEPROJECT_ITEM_H

#include <iostream>
#include <utility>

class Item {
private:
    const std::string name;
    const int price;
    const int requiredLevel;

public:
    Item(std::string  name, int price, int level): name(std::move(name)), price(price), requiredLevel(level){}
    virtual ~Item() = 0;

    std::string getName() const{
        return name;
    }
    int getPrice() const{
        return price;
    }
    int getRequiredLevel() const{
        return requiredLevel;
    }

    virtual int getAttribute() const = 0;
    virtual void print() const = 0;
};


#endif //GAMEPROJECT_ITEM_H