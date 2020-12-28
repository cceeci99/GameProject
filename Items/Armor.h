#include "Item.h"

#ifndef GAMEPROJECT_ARMOR_H
#define GAMEPROJECT_ARMOR_H


class Armor: public Item {
private:
    const int defence;

public:
    Armor(const std::string& name, int price, int level, int defence): Item(name, price, level), defence(defence){};

    ~Armor() override = default;

    void print() const override;

    int getAttribute() const override;
};


#endif //GAMEPROJECT_ARMOR_H
