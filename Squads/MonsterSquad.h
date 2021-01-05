
#ifndef GAMEPROJECT_MONSTERSQUAD_H
#define GAMEPROJECT_MONSTERSQUAD_H

#include "../Creatures/Monsters/Monster.h"


class MonsterSquad {

private:

    Monster** squad;
    int mobs=0;

public:

    explicit MonsterSquad(int mobs);

    ~MonsterSquad();

    int getSize() const;

    void print() const;

    void setMonster(Monster* monster);

    Monster* getMonster(int pos) const;

    Monster** getSquad() const;

    bool wiped() const;

    void regeneration();

};


#endif //GAMEPROJECT_MONSTERSQUAD_H