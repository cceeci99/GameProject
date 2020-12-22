#ifndef GAMEPROJECT_WEAPON_H
#define GAMEPROJECT_WEAPON_H

#include <iostream>
#include <utility>
#include "Item.h"

class Weapon: public Item {
private:
    const int damage;
    const bool oneHanded;

public:
    Weapon(const std::string& name, double price, int level, int damage, bool oneHanded): Item(std::move(name), price, level), damage(damage), oneHanded(oneHanded){}
    ~Weapon() override = default;

    int getDamage() const{
        return damage;
    }
    bool isOneHanded() const{
        return oneHanded;
    }

    void print() const override{
        std::cout << "Weapon " << getName();
    }

};

#endif //GAMEPROJECT_WEAPON_H
