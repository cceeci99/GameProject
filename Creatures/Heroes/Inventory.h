#include "../../Items/Item.h"
#include "../../Spells/Spell.h"

#include <iostream>
#include <vector>

#ifndef GAMEPROJECT_INVENTORY_H
#define GAMEPROJECT_INVENTORY_H


class Inventory {
private:
    std::vector<Item*> items;
    std::vector<Spell*> spells;

public:
    ~Inventory(){
        items.clear();
        spells.clear();
    }

    void addItem(Item* newItem){
        items.push_back(newItem);
    }

    void addSpell(Spell* newSpell){
        spells.push_back(newSpell);
    }

    Item * getItem(int pos) const {
        return items.at(pos);
    }

    void print() const{
        int k=1;
        for(Item* i: items)
        {
            if ( i != nullptr ) {
                std::cout << k << ")";
                i->print();
                k++;
            }
        }
        for(Spell* s: spells)
        {
            if ( s != nullptr ) {
                std::cout << k << ")";
                s->print();
            }
        }
    }
};


#endif //GAMEPROJECT_INVENTORY_H
