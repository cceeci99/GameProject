#include <iostream>

#include "Game.h"
#include "Spells/IceSpell.h"
#include "Spells/FireSpell.h"


int main(int args, char* argv[]) {

    std::vector<Item*> items;
    std::vector<Spell*> spells;

    Item* armor = new Armor("Emblem", 122, 1, 450);
    Item* armor1 = new Armor("hat", 50, 1, 25);
    Item* weapon = new Weapon("axe", 145, 1, 420, true);
    Item* weapon1 = new Weapon("sword", 100, 1, 200, false);
    Item* potion = new Potion("Antidote", 45, 1, Health, 101);

    items.push_back(armor);
    items.push_back(armor1);
    items.push_back(weapon);
    items.push_back(weapon1);
    items.push_back(potion);

    Spell* spell = new FireSpell("inferno", 45, 1, 110, Range::getRandomRange(100, 500), 150);
    Spell* spell1 = new IceSpell("iceball", 50, 1, 1100, Range::getRandomRange(500, 1000), 80);

    spells.push_back(spell);
    spells.push_back(spell1);


    Game* game = new Game();

    game->fillMarket(items, spells);

    game->createMap(5);

    game->play();

    items.clear();
    spells.clear();
    delete armor1;
    delete weapon1;
    delete spell;
    delete spell1;
    delete potion;
    delete weapon;
    delete armor;
    delete game;

    return 0;
}
