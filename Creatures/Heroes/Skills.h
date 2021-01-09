
#ifndef GAMEPROJECT_SKILLS_H
#define GAMEPROJECT_SKILLS_H

#include "../../Spells/Spell.h"

#define SPELLS_LIMIT 10


class Skills {

private:
    int acquiredSpells = 0;
    Spell** spells = new Spell*[SPELLS_LIMIT];

public:

    Skills() = default;

    ~Skills() {
        delete[] spells;
    };

    bool empty() const;

    void print() const;

    bool addSpell(Spell* newSpell);

    Spell* getSpell(int pos);
    Spell* removeSpell(int pos);

};


#endif //GAMEPROJECT_SKILLS_H