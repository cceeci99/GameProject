
#ifndef GAMEPROJECT_MONSTERSQUAD_H
#define GAMEPROJECT_MONSTERSQUAD_H

#include "../Creatures/Monsters/Monster.h"


class MonsterSquad {

private:

    Monster** monsters;
    int numberOfMonsters=0;

public:

    explicit MonsterSquad(int n);

    ~MonsterSquad();

    void print() const;

    int getSize() const;

    Monster* getMonster(int pos) const;
    void setMonster(Monster* monster);

    bool defeated() const;
    void regeneration();

    void unchargeActiveSpells();

};


#endif //GAMEPROJECT_MONSTERSQUAD_H