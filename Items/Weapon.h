
#ifndef GAMEPROJECT_WEAPON_H
#define GAMEPROJECT_WEAPON_H

#include "Item.h"


class Weapon: public Item {

private:
    //weapon's attribute is damage
    const int damage;
    const bool oneHanded;
    std::string weaponType;

public:

    Weapon(const std::string& name, int price, int level, int damage, bool oneHanded)
    :Item(name, price, level, weapon), damage(damage), oneHanded(oneHanded){
        if ( oneHanded )
            weaponType = "one handed";
        else
            weaponType = "both hands";
    }

    ~Weapon() override = default;

    void print() const override;

    int getAttribute() const override;

};


#endif //GAMEPROJECT_WEAPON_H