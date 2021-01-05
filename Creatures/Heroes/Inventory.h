
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

    bool empty() const;

    Item * getItem(int pos) ;

    Item* changeItem(int pos, Item* item);

    void addItem(Item* newItem);

    Item* removeItem(int pos);

    void print() const;

    Potion* choosePotion();

};



#endif //GAMEPROJECT_INVENTORY_H