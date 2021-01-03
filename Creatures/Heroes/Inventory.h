#include <vector>
#include "../../Items/Item.h"
#include "../../Items/Potion.h"


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

    bool empty() const;

    Item * getItem(int pos) ;

    Item* changeItem(int pos, Item* item);

    void addItem(Item* newItem);

    Item* removeItem(int pos);

    void print() const;

    Potion* choosePotion(){
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

            for (int i=0; i<INVENTORY_CAPACITY; i++)
            {
                if ( items[i] == temp )
                {
                    removeItem(i);
                }
            }
            potions.clear();
            return temp;
        }
    }
};



#endif //GAMEPROJECT_INVENTORY_H