
#ifndef GAMEPROJECT_FIGHT_H
#define GAMEPROJECT_FIGHT_H

#include <cstdlib>

#include "Squads/HeroSquad.h"
#include "Squads/MonsterSquad.h"


class Fight {

private:
    HeroSquad* heroes;
    MonsterSquad* enemies;

public:

    Fight(HeroSquad* heroes, MonsterSquad* enemies)
    :heroes(heroes), enemies(enemies){};

    ~Fight(){
        delete enemies;
    }

    static bool begin();

    bool isOver() const;

    void displayStats() const;

    void battle(int round);

};


#endif //GAMEPROJECT_FIGHT_H
