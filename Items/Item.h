#ifndef GAMEPROJECT_ITEM_H
#define GAMEPROJECT_ITEM_H

#include <iostream>
#include <utility>

class Item {
private:
    const string name;
    const double price{};
    const int requiredLevel{};

public:
    Item(string  name, double price, level): name(move(name)), price(price), requiredLevel(level){}
    virtual ~Item() = 0;

    string getName() const{
        return name;
    }
    double getPrice() const{
        return price;
    }
    int getRequiredLevel() const{
        return requiredLevel;
    }

    virtual void print() const = 0;
}


#endif //GAMEPROJECT_ITEM_H
