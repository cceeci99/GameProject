#include <iostream>
#include "Creatures/Heroes/Warrior.h"
#include "Items/Armor.h"
#include "Spells/FireSpell.h"
#include "Spells/IceSpell.h"

#include "MarketPlace/Market.h"

using namespace std;

int main(int args, char* argv[]) {

    Hero* warrior = new Warrior("Kratos");

    Item* armor = new Armor("Emblem", 122, 1, 450);
    Item* armor1 = new Armor("hat", 50, 1, 25);
    Item* weapon = new Weapon("axe", 145, 1, 420, true);
    Item* weapon1 = new Weapon("sword", 100, 1, 200, false);


    Item* potion = new Potion("Antidote", 45, 1, Health, 101);

    Spell* spell = new FireSpell("inferno", 45, 1, 110, Range::getRandomRange(100, 500), 150);

    Spell* spell1 = new IceSpell("iceball", 50, 1, 1100, Range::getRandomRange(500, 1000), 80);


    Market marketPlace;
    marketPlace.addItem(armor);
    marketPlace.addItem(armor1);
    marketPlace.addItem(weapon);
    marketPlace.addItem(weapon1);
    marketPlace.addItem(potion);
    marketPlace.addSpell(spell);
    marketPlace.addSpell(spell1);

    marketPlace.open(warrior);

    warrior->checkInventory();

    delete armor1;
    delete weapon1;
    delete spell;
    delete spell1;
    delete potion;
    delete weapon;
    delete armor;
    delete warrior;

    return 0;
}
