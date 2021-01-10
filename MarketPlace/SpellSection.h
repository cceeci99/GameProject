
#ifndef GAMEPROJECT_SPELLSECTION_H
#define GAMEPROJECT_SPELLSECTION_H

#include "../Creatures/Heroes/Hero.h"

#define SPELLS_CAPACITY 50


class SpellSection {

private:
    int addedSpells = 0;
    Spell** spells = new Spell*[SPELLS_CAPACITY];


    void buyOption(Hero* hero);
    void sellOption(Hero* hero) const;

    Spell* getSpell(int pos);

public:

    SpellSection() = default;

    ~SpellSection(){
        for (int i=0; i<SPELLS_CAPACITY; i++)
        {
            if (spells[i] != nullptr) {
                delete spells[i];
            }
        }

        delete[] spells;
    }

    void print() const;

    void open(Hero* hero);

    void addSpell(Spell* newSpell);

};


#endif //GAMEPROJECT_SPELLSECTION_H