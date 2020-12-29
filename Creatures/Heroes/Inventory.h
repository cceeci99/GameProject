#include "../../Items/Item.h"
#include "../../Spells/Spell.h"

#include <iostream>
#include <vector>

#ifndef GAMEPROJECT_INVENTORY_H
#define GAMEPROJECT_INVENTORY_H


class Inventory {

private:
    std::vector<Item*> items;

public:

    ~Inventory(){
        items.clear();
    }

    Item * getItem(int pos) const {
        return items.at(pos);
    }

    void addItem(Item* newItem){
        items.push_back(newItem);
    }

    void removeItem(Item* item){
        for(Item* i: items)
        {
            if ( i == item ) {
                i = nullptr;
            }
        }
    }

    void print() const{
        int k=1;
        for(Item* i: items)
        {
            if ( i != nullptr )
            {
                std::cout << k << ")";
                i->print();
                k++;
            }
        }
    }
};


#endif //GAMEPROJECT_INVENTORY_H
