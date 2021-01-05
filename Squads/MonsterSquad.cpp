#include "MonsterSquad.h"

MonsterSquad::MonsterSquad(int mobs) {
    //allocate memory for number of mobs which will be given by the user
    squad = new Monster*[mobs];
    this->mobs = mobs;
}

MonsterSquad::~MonsterSquad() {
    for(int i=0; i < mobs; i++)
        delete squad[i];

    delete[] squad;
}

int MonsterSquad::getSize() const {
    return mobs;
}

void MonsterSquad::print() const {
    for (int i=0; i < mobs; i++){
        squad[i]->print();
    }
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

Monster *MonsterSquad::getMonster(int pos) const {
    if (pos >= mobs )
        return nullptr;

    return squad[pos];
}

Monster **MonsterSquad::getSquad() const {
    return squad;
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
