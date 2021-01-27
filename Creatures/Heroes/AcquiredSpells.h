
#ifndef GAMEPROJECT_ACQUIREDSPELLS_H
#define GAMEPROJECT_ACQUIREDSPELLS_H

#include "../../Spells/Spell.h"

#define SPELLS_LIMIT 10

//this class implements the acquired spells of some hero

class AcquiredSpells {

private:
    int acquiredSpells = 0;

    Spell** spells = new Spell*[SPELLS_LIMIT];

public:

    AcquiredSpells();

    ~AcquiredSpells();

    bool empty() const;

    void print() const;

    bool addSpell(Spell* newSpell);

    Spell* getSpell(int pos);
    Spell* removeSpell(int pos);

};


#endif //GAMEPROJECT_ACQUIREDSPELLS_H