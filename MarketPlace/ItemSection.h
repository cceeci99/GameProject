
#ifndef GAMEPROJECT_ITEMSECTION_H
#define GAMEPROJECT_ITEMSECTION_H

#include "../Creatures/Heroes/Hero.h"

#define ITEMS_CAPACITY 50


class ItemSection {

private:
    int addedItems = 0;
    Item** items = new Item*[ITEMS_CAPACITY];


    void buyOption(Hero* hero);

    void sellOption(Hero* hero) const;


    Item* getItem(int pos);

public:

    ItemSection() = default;

    ~ItemSection(){
        for (int i=0; i<ITEMS_CAPACITY; i++)
        {
            if ( items[i]  != nullptr ) {
                delete items[i];
            }
        }

        delete[] items;
    }

    void print() const;

    void open(Hero* hero);

    void addItem(Item* newItem);
};


#endif //GAMEPROJECT_ITEMSECTION_H
