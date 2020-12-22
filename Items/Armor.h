#include <utility>

#include "Item.h"

#ifndef GAMEPROJECT_ARMOR_H
#define GAMEPROJECT_ARMOR_H


class Armor: public Item {
private:
    const int defence;

public:
    Armor(const std::string& name, double price, int level, int defence): Item(std::move(name), price, level), defence(defence){};
    ~Armor() override = default;

    int getDefence() const{
        return defence;
    }
    void print() const override{
        std::cout << "Armor " << getName;
    }
};


#endif //GAMEPROJECT_ARMOR_H
