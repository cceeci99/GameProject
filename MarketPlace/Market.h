
#ifndef GAMEPROJECT_MARKET_H
#define GAMEPROJECT_MARKET_H

#include "SpellSection.h"
#include "ItemSection.h"


class Market {

private:

    // A market has section with items and spells
    SpellSection spellSection;
    ItemSection itemSection;

public:

    Market() = default;

    ~Market() = default;

    void open(Hero* hero);

    void addItem(Item* newItem);        //function used at the beginning for filling the market with items

    void addSpell(Spell* newSpell);     //function used at the beginning for filling the market with spells

};


#endif //GAMEPROJECT_MARKET_H