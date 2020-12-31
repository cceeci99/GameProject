#include "../../Items/Item.h"


#ifndef GAMEPROJECT_INVENTORY_H
#define GAMEPROJECT_INVENTORY_H

#define INVENTORY_CAPACITY 20


class Inventory {

private:
    int addedItems = 0;
    Item** items = new Item*[INVENTORY_CAPACITY];

public:

    ~Inventory() {
        delete[] items;
    };

    Item * getItem(int pos) ;

    Item* changeItem(int pos, Item* item);

    void addItem(Item* newItem);

    Item* removeItem(int pos);

    void print() const;

};



#endif //GAMEPROJECT_INVENTORY_H