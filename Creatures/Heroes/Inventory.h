
#ifndef GAMEPROJECT_INVENTORY_H
#define GAMEPROJECT_INVENTORY_H

#include <vector>
#include "../../Items/Item.h"
#include "../../Items/Potion.h"

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

    void addItem(Item* newItem);

    Item * getItem(int pos);
    Item* changeItem(int pos, Item* item);
    Item* removeItem(int pos);

    Potion* choosePotion();

};



#endif //GAMEPROJECT_INVENTORY_H