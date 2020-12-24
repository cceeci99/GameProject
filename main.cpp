#include <iostream>

#include "Creatures/Heroes/Warrior.h"

int main() {

    auto* warrior = new Warrior("Kratos");
    warrior->print();

    delete warrior;

    return 0;
}
