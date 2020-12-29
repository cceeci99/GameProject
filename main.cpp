#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Creatures/Heroes/Warrior.h"
#include "Spells/FireSpell.h"

using namespace std;

int main(int args, char* argv[]) {

    // read names from file
    vector<string> names;

    string name;
    ifstream file;
    file.open(argv[1]);

    while(getline(file, name)){
        names.push_back(name);
    }
    srand(time(nullptr));
    int r = random() % names.size();

    Hero* warrior = new Warrior(names.at(r));
    warrior->print();

    Item* item = new Weapon("Sword", 45, 1, 150, true);
    warrior->buyItem(item);

    Spell* spell = new FireSpell("inferno" , 78, 1, 14, Range::getRandomRange(50, 80), 32);
    warrior->buySpell(spell);

    warrior->checkInventory();
    warrior->sellItem(item);
    warrior->checkInventory();


    delete warrior;
    delete item;
    delete spell;

    return 0;
}
