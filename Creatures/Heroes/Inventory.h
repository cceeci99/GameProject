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

    void print() const{
        for(Item* i: items)
        {
            if ( i != nullptr ) {
                i->print();
            }
        }
        for(Spell* s: spells)
        {
            if ( s != nullptr ) {
                s->print();
            }
        }
    }
};


#endif //GAMEPROJECT_INVENTORY_H
