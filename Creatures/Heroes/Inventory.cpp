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


Item* Inventory::removeItem(int pos) {
    if ( pos >= INVENTORY_CAPACITY  || items[pos] == nullptr)
        return nullptr;

    Item* temp = items[pos];

    items[pos] = nullptr;
    addedItems--;

    return temp;
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

    int pos;
    std::cin >> pos;

    if ( pos == 0 )
        return nullptr;
    else
    {

        Potion* temp = potions.at(pos-1);

        removeItem(temp);

        /*
        for (int i=0; i<INVENTORY_CAPACITY; i++)
        {
            if ( items[i] == temp )
            {
                removeItem(i);
            }
        }*/

        return temp;
    }
}