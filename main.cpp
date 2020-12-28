#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Creatures/Heroes/Warrior.h"

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

    int r = random() % names.size();

    Hero* warrior = new Warrior(names.at(r));
    warrior->print();

    delete warrior;

    return 0;
}
