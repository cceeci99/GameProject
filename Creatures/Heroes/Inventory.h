
#ifndef GAMEPROJECT_INVENTORY_H
#define GAMEPROJECT_INVENTORY_H

#include <vector>
#include "../../Items/Item.h"
#include "../../Items/Potion.h"
#include "../../Items/Armor.h"
#include "../../Items/Weapon.h"

#define INVENTORY_CAPACITY 20


class Inventory {

private:
    int addedItems = 0;
    Item** items = new Item*[INVENTORY_CAPACITY];

public:

    ~Inventory() {
        delete[] items;
    };

    void print() const;

    bool empty() const;

    bool addItem(Item* newItem);



    Item * getItem(int pos);
    Item* changeItem(int pos, Item* item);
    Item* removeItem(int pos);

    void removeItem(Item* item){
        for (int i=0; i<INVENTORY_CAPACITY; i++)
        {
            if ( items[i] == item )
            {
                items[i] = nullptr;
                return;
            }
        }
    }

    Potion* choosePotion();



    void showEquipment(Armor* arm, Weapon* wep) {
        std::vector<Armor*> armors;
        std::vector<Weapon*> weapons;

        arm = nullptr;
        wep = nullptr;

        int k=1;
        for (int i=0; i<INVENTORY_CAPACITY; i++)
        {
            if ( items[i] == nullptr )
                continue;

            if ( items[i]->getType() == armor )
            {
                std::cout << k << ")";
                k++;
                items[i]->print();
                armors.push_back((Armor*)items[i]);
            }
        }
        std::cout << "Choose armor" << std::endl;

        int pos;
        std::cin >> pos;

        if ( pos != 0 )
        {
            arm  = armors.at(pos-1);
            if (arm != nullptr) {
                std::cout << "yes" << std::endl;
                std::cout << arm->getName() << std::endl;
            }

            removeItem(arm);
        }

        k=1;
        for (int i=0; i<INVENTORY_CAPACITY; i++)
        {
            if ( items[i] == nullptr )
                continue;

            if ( items[i]->getType() == weapon )
            {
                std::cout << k << ")";
                k++;
                items[i]->print();
                weapons.push_back((Weapon*)items[i]);
            }
        }
        std::cout << "Choose weapon" << std::endl;

        std::cin >> pos;

        if ( pos != 0 )
        {
            wep  = weapons.at(pos-1);
            removeItem(wep);
        }
    }

};


#endif //GAMEPROJECT_INVENTORY_H