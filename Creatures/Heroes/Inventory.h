#include "../../Items/Item.h"
#include "../../Spells/Spell.h"

#include "../../List.h"

#ifndef GAMEPROJECT_INVENTORY_H
#define GAMEPROJECT_INVENTORY_H


class Inventory {

private:
//    List<Item*> items;
    int capacity = 20;
    int addedItems = 0;
    Item** items = new Item*[capacity];

public:

    ~Inventory() {
        delete[] items;
    };

    Item * getItem(int pos) ;

    Item* changeItem(int pos, Item* item);

    void addItem(Item* newItem);

    void removeItem(int pos);

    void print() const;

};


#endif //GAMEPROJECT_INVENTORY_H