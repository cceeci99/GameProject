#include "Item.h"

#ifndef GAMEPROJECT_ARMOR_H
#define GAMEPROJECT_ARMOR_H


class Armor: public Item {
private:
    const int defence;

public:
    Armor(const std::string& name, int price, int level, int defence): Item(name, price, level), defence(defence){};
    ~Armor() override = default;

    int getAttribute() const override{
        return defence;
    }
    void print() const override{
        std::cout << "Armor " << getName() << " Defence " << defence;
    }
};


#endif //GAMEPROJECT_ARMOR_H
