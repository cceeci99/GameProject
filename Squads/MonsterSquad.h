
#ifndef GAMEPROJECT_MONSTERSQUAD_H
#define GAMEPROJECT_MONSTERSQUAD_H

#include "../Creatures/Monsters/Monster.h"


class MonsterSquad {

private:

    Monster** squad;
    int mobs=0;

public:

    explicit MonsterSquad(int mobs){
        squad = new Monster*[mobs];
        this->mobs = mobs;
    }

    ~MonsterSquad(){
        for(int i=0; i < mobs; i++)
            delete squad[i];

        delete[] squad;
    }

    void print() const;

    int getSize() const;

    Monster* getMonster(int pos) const;
    void setMonster(Monster* monster);

    bool wiped() const;
    void regeneration();

};


#endif //GAMEPROJECT_MONSTERSQUAD_H