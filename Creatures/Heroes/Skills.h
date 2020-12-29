#include <iostream>
#include "../../Spells/Spell.h"

#include "../../List.h"

#ifndef GAMEPROJECT_SKILLS_H
#define GAMEPROJECT_SKILLS_H


class Skills {

private:
    int maxSpells = 10;
    int acquiredSpells = 0;

//    List<Spell*> spells;
    Spell** spells = new Spell*[maxSpells];

public:

    ~Skills() {
        delete[] spells;
    };

    Spell* getSpell(int pos);

    void addSpell(Spell* newSpell);

    void removeSpell(int pos);

    void print() const;
};


#endif //GAMEPROJECT_SKILLS_H
