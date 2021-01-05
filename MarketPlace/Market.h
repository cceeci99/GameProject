
#ifndef GAMEPROJECT_MARKET_H
#define GAMEPROJECT_MARKET_H

#include "SpellSection.h"
#include "ItemSection.h"


class Market {

private:

    SpellSection spellSection;
    ItemSection itemSection;

public:

    Market() = default;

    ~Market() = default;

    void open(Hero* hero);

    void addItem(Item* newItem);

    void addSpell(Spell* newSpell);

};


#endif //GAMEPROJECT_MARKET_H