#include "Skills.h"

void Skills::addSpell(Spell *newSpell) {
    if ( acquiredSpells >= maxSpells )
    {
        std::cout << "You already have the max number of spells, cannot add new one" << std::endl;
    }

    for(int i=0; i<maxSpells; i++)
    {
        if ( spells[i] == nullptr )
        {
            spells[i] = newSpell;
            acquiredSpells++;
            return;
        }
    }
}

void Skills::removeSpell(int pos) {
    if (pos >= maxSpells)
        return;

    spells[pos] = nullptr;
}

Spell* Skills::getSpell(int pos){
    if (pos >= maxSpells)
        return nullptr;

    return spells[pos];
}

void Skills::print() const {
    for(int k=0; k<maxSpells; k++)
    {
        if ( spells[k] != nullptr )
        {
            std::cout << k+1 << ")";
            spells[k]->print();
        }
    }
}