
#ifndef GAMEPROJECT_SKILLS_H
#define GAMEPROJECT_SKILLS_H

#include "../../Spells/Spell.h"

#define SPELLS_LIMIT 10


class Skills {

private:
    int acquiredSpells = 0;
    Spell** spells = new Spell*[SPELLS_LIMIT];

public:

    ~Skills() {
        delete[] spells;
    };

    Spell* getSpell(int pos);

    void addSpell(Spell* newSpell);

    Spell* removeSpell(int pos);

    void print() const;
};


#endif //GAMEPROJECT_SKILLS_H
