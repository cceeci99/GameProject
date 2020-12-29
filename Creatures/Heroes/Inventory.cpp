#include "Inventory.h"


Item *Inventory::getItem(int pos)  {
//    return items.get(pos);
    if ( pos >= capacity )
        return nullptr;

    return items[pos];
}

Item *Inventory::changeItem(int pos, Item *item) {
//    return items.swap(pos, item);
    if ( pos >= capacity )
        return nullptr;

    Item* temp = items[pos];
    items[pos] = item;
    return temp;
}

void Inventory::addItem(Item *newItem) {
//    items.add(newItem);
    if ( addedItems >= 10 )
    {
        std::cout << "Inventory full cant add new item" << std::endl;
        return;
    }

    for(int i=0; i < capacity; i++)
    {
        if ( items[i] == nullptr )
        {
            items[i] = newItem;
            addedItems++;
            return;
        }
    }
}

void Inventory::removeItem(int pos) {
//    items.remove(item);
    if ( pos >= capacity )
        return;

    items[pos] = nullptr;
    addedItems--;
}

void Inventory::print() const {

    for(int i=0; i < capacity; i++)
    {
        if ( items[i] != nullptr )
        {
            std::cout << i + 1 << ")";
            items[i]->print();
        }
    }
}
