#include "Skills.h"


void Skills::print() const {
    for(int k=0; k<SPELLS_LIMIT; k++)
    {
        if ( spells[k] != nullptr )
        {
            std::cout << k+1 << ")";
            spells[k]->print();
        }
    }
}


bool Skills::addSpell(Spell *newSpell) {
    if ( acquiredSpells >= SPELLS_LIMIT )
    {
        std::cout << "You already have the max number of spells, cannot add new one" << std::endl;
    }

    bool result = true;
    for (int i=0; i<SPELLS_LIMIT; i++)
    {
        if ( spells[i] == newSpell )
        {
            std::cout << "You already have that spell choose another" << std::endl;
            result = false;
            break;
        }
    }

    if (!result)
        return result;

    for(int i=0; i<SPELLS_LIMIT; i++)
    {
        if ( spells[i] == nullptr )
        {
            spells[i] = newSpell;
            acquiredSpells++;
            break;
        }
    }

    return result;
}


Spell* Skills::getSpell(int pos) {
    if (pos >= SPELLS_LIMIT)
        return nullptr;

    return spells[pos];
}


Spell* Skills::removeSpell(int pos) {
    if (pos >= SPELLS_LIMIT || spells[pos] == nullptr)
        return nullptr;

    Spell* temp = spells[pos];

    spells[pos] = nullptr;
    acquiredSpells--;

    return temp;
}