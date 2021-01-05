
#ifndef GAMEPROJECT_SPELLSECTION_H
#define GAMEPROJECT_SPELLSECTION_H

#include "../Creatures/Heroes/Hero.h"

#define SPELLS_CAPACITY 50


class SpellSection {

private:
    int addedSpells = 0;
    Spell** spells = new Spell*[SPELLS_CAPACITY];

public:

    ~SpellSection(){
        delete[] spells;
    }

    void buyOption(Hero* hero);

    void sellOption(Hero* hero) const;

    void open(Hero* hero);

    void print() const;

    void addSpell(Spell* newSpell);

    Spell* getSpell(int pos);

};


#endif //GAMEPROJECT_SPELLSECTION_H
