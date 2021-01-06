
#ifndef GAMEPROJECT_MONSTERSQUAD_H
#define GAMEPROJECT_MONSTERSQUAD_H

#include "../Creatures/Monsters/Monster.h"


class MonsterSquad {

private:

    Monster** monsters;
    int numberOfMonsters=0;

public:

    explicit MonsterSquad(int mobs){
        monsters = new Monster*[mobs];
        this->numberOfMonsters = mobs;
    }

    ~MonsterSquad(){
        for(int i=0; i < numberOfMonsters; i++)
            delete monsters[i];

        delete[] monsters;
    }

    void print() const;

    int getSize() const;

    Monster* getMonster(int pos) const;
    void setMonster(Monster* monster);

    bool defeated() const;
    void regeneration();

};


#endif //GAMEPROJECT_MONSTERSQUAD_H