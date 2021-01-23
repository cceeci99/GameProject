#include "AcquiredSpells.h"


AcquiredSpells::AcquiredSpells() {
    for (int i=0; i<SPELLS_LIMIT; i++)
    {
        spells[i] = nullptr;
    }
}

AcquiredSpells::~AcquiredSpells() {
    delete[] spells;
}


bool AcquiredSpells::empty() const {
    return acquiredSpells == 0;
}


void AcquiredSpells::print() const {
    for(int k=0; k<SPELLS_LIMIT; k++)
    {
        if ( spells[k] != nullptr )
        {
            std::cout << k+1 << ")";
            spells[k]->print();
        }
    }
}


bool AcquiredSpells::addSpell(Spell *newSpell) {
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


Spell* AcquiredSpells::getSpell(int pos) {
    if (pos >= SPELLS_LIMIT || pos < 0)
        return nullptr;

    return spells[pos];
}


Spell* AcquiredSpells::removeSpell(int pos) {
    if (pos >= SPELLS_LIMIT || spells[pos] == nullptr)
        return nullptr;

    Spell* temp = spells[pos];

    spells[pos] = nullptr;
    acquiredSpells--;

    return temp;
}