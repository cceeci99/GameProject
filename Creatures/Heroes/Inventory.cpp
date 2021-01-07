#include "Inventory.h"


void Inventory::print() const {

    for(int i=0; i < INVENTORY_CAPACITY; i++)
    {
        if ( items[i] != nullptr )
        {
            std::cout << i + 1 << ")";
            items[i]->print();
        }
    }
}


bool Inventory::empty() const {
    return addedItems == 0;
}


bool Inventory::addItem(Item *newItem) {
    if ( addedItems >= INVENTORY_CAPACITY)
    {
        std::cout << "Inventory full cant add new item" << std::endl;
    }

    bool result = true;
    for(int i=0; i<INVENTORY_CAPACITY; i++)
    {
        if ( items[i] == newItem )
        {
            std::cout << "You already have that item choose another" << std::endl;
            result = false;
            break;
        }
    }

    if (!result)
        return result;


    for(int i=0; i < INVENTORY_CAPACITY; i++)
    {
        if ( items[i] == nullptr )
        {
            items[i] = newItem;
            addedItems++;
            break;
        }
    }

    return result;
}


Item *Inventory::getItem(int pos)  {
    if ( pos >= INVENTORY_CAPACITY )
        return nullptr;

    return items[pos];
}


Item *Inventory::changeItem(int pos, Item *item) {
    if ( pos >= INVENTORY_CAPACITY )
        return nullptr;

    Item* temp = items[pos];
    items[pos] = item;
    return temp;
}


void Inventory::changeItem(Item *item1, Item *item2) {
    for (int i=0; i<INVENTORY_CAPACITY; i++)
    {
        if (items[i] == item1){
            items[i] = item2;
        }
    }
}


Item* Inventory::removeItem(int pos) {
    if ( pos >= INVENTORY_CAPACITY  || items[pos] == nullptr)
        return nullptr;

    Item* temp = items[pos];

    items[pos] = nullptr;
    addedItems--;

    return temp;
}


void Inventory::removeItem(Item *item) {
    for (int i=0; i<INVENTORY_CAPACITY; i++)
    {
        if ( items[i] == item )
        {
            items[i] = nullptr;
            return;
        }
    }
}

Potion *Inventory::choosePotion() {
    int k=1;

    std::vector<Potion*> potions;

    for (int i=0; i<INVENTORY_CAPACITY; i++)
    {
        if ( items[i] == nullptr )
            continue;

        if ( items[i]->getType() == potion )
        {
            std::cout << k << ")";
            k++;
            items[i]->print();
            potions.push_back((Potion*)items[i]);
        }
    }

    if (potions.empty())
    {
        std::cout << "None available potions" << std::endl;
        return nullptr;
    }

    int pos;
    while (true)
    {
        std::cin >> pos;
        if ( pos > potions.size() )
            std::cout << "Please choose available potion" << std::endl;
        else
            break;

    }

    std::cin >> pos;

    if ( pos != 0 )
    {

        Potion* temp = potions.at(pos-1);

        removeItem(temp);

        return temp;
    }
    else
        return nullptr;
}

Armor *Inventory::chooseArmor() {
    std::vector<Armor*> armors;
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

    if (armors.empty())
    {
        std::cout << "None available armors" << std::endl;
        return nullptr;
    }

    int pos;
    while (true)
    {
        std::cin >> pos;
        if ( pos > armors.size() )
            std::cout << "Please choose available armor" << std::endl;
        else
            break;

    }

    if ( pos != 0 )
    {
        Armor* arm =  armors.at(pos-1);
        return arm;
    }
    else
        return nullptr;
}

Weapon *Inventory::chooseWeapon() {
    std::vector<Weapon*> weapons;
    int k=1;
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

    if (weapons.empty())
    {
        std::cout << "None available potions" << std::endl;
        return nullptr;
    }

    int pos;
    while (true)
    {
        std::cin >> pos;
        if ( pos > weapons.size() )
            std::cout << "Please choose available weapon" << std::endl;
        else
            break;

    }

    if ( pos != 0 )
    {
        Weapon* weap =  weapons.at(pos-1);
        return weap;
    }
    else
        return nullptr;
}
