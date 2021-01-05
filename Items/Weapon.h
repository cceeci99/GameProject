
#ifndef GAMEPROJECT_WEAPON_H
#define GAMEPROJECT_WEAPON_H

#include "Item.h"

class Weapon: public Item {

private:
    const int damage;
    const bool oneHanded;
    std::string weaponType;

public:

    Weapon(const std::string& name, int price, int level, int damage, bool oneHanded, ItemType type = weapon)
    :Item(name, price, level, type), damage(damage), oneHanded(oneHanded){
        if ( oneHanded )
            weaponType = "one handed";
        else
            weaponType = "both hands";
    }

    ~Weapon() override = default;

    void print() const override;

    int getAttribute() const override;

    bool isOneHanded() const;

};


#endif //GAMEPROJECT_WEAPON_H