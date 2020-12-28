#ifndef GAMEPROJECT_WEAPON_H
#define GAMEPROJECT_WEAPON_H

#include <iostream>
#include <utility>
#include "Item.h"

class Weapon: public Item {
private:
    const int damage;
    const bool oneHanded;
    std::string type;

public:
    Weapon(const std::string& name, int price, int level, int damage, bool oneHanded): Item(name, price, level), damage(damage), oneHanded(oneHanded){
        if ( oneHanded )
            type = "one handed";
        else
            type = "both hands";
    }

    ~Weapon() override = default;

    bool isOneHanded() const;

    void print() const override;

    int getAttribute() const override;

};

#endif //GAMEPROJECT_WEAPON_H
