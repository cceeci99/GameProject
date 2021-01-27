
#ifndef GAMEPROJECT_SPELLSECTION_H
#define GAMEPROJECT_SPELLSECTION_H

#include "../Creatures/Heroes/Hero.h"

#define SPELLS_CAPACITY 50


class SpellSection {

private:
    int addedSpells = 0;

    Spell** spells = new Spell*[SPELLS_CAPACITY];

    //buy and sell methods are encapsulated in market
    void buyOption(Hero* hero);

    static void sellOption(Hero* hero);

    Spell* getSpell(int pos);

public:

    SpellSection();

    ~SpellSection();

    void print() const;

    void open(Hero* hero);

    void addSpell(Spell* newSpell);     //function used at the beginning for filling the market with spells

};


#endif //GAMEPROJECT_SPELLSECTION_H