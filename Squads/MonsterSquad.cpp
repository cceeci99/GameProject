#include "MonsterSquad.h"


void MonsterSquad::print() const {
    for (int i=0; i < mobs; i++){
        squad[i]->print();
    }
}


int MonsterSquad::getSize() const {
    return mobs;
}


Monster *MonsterSquad::getMonster(int pos) const {
    if (pos >= mobs )
        return nullptr;

    return squad[pos];
}


void MonsterSquad::setMonster(Monster *monster) {
    for(int i=0; i < mobs; i++)
    {
        if (squad[i] == nullptr )
        {
            squad[i] = monster;
            return;
        }
    }
}


bool MonsterSquad::wiped() const {
    int totalHealth=0;
    for(int i=0; i<mobs; i++){
        totalHealth += squad[i]->getHealth();
    }

    return (totalHealth==0);
}


void MonsterSquad::regeneration() {
    for(int i=0; i<mobs; i++){
        squad[i]->regeneration();
    }
}