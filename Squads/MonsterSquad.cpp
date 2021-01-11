#include "MonsterSquad.h"

MonsterSquad::MonsterSquad(int n) {

    monsters = new Monster*[n];

    for (int i = 0; i < n; i++)
    {
        monsters[i] = nullptr;
    }

    numberOfMonsters = n;
}


MonsterSquad::~MonsterSquad() {

    for(int i = 0; i < numberOfMonsters; i++)
    {
        if (monsters[i] != nullptr)
        {
            delete monsters[i];
        }
    }

    delete[] monsters;
}


void MonsterSquad::print() const {

    for (int i = 0; i < numberOfMonsters; i++)
    {
        if (!monsters[i]->dead())
        {
            std::cout << i+1 << ")";
            monsters[i]->print();
        }
    }

    std::cout << std::endl;
}


int MonsterSquad::getSize() const {
    return numberOfMonsters;
}


Monster *MonsterSquad::getMonster(int pos) const {
    if (pos >= numberOfMonsters)
        return nullptr;

    return monsters[pos];
}


void MonsterSquad::setMonster(Monster *monster) {
    for(int i=0; i < numberOfMonsters; i++)
    {
        if (monsters[i] == nullptr)
        {
            monsters[i] = monster;
            return;
        }
    }
}


bool MonsterSquad::defeated() const {

    int total = 0;
    for(int i=0; i < numberOfMonsters; i++)
    {
        if (monsters[i]->dead())
        {
            total++;
        }
    }

    return (total == numberOfMonsters);
}


void MonsterSquad::regeneration() {

    for(int i = 0; i < numberOfMonsters; i++)
    {
        monsters[i]->regenerate();
    }
}

void MonsterSquad::unchargeActiveSpells() {

    for (int i = 0; i < numberOfMonsters; i++)
    {
        monsters[i]->reduceSpellsDuration();
        monsters[i]->checkExpiredSpells();
    }
}