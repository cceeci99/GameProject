
#ifndef GAMEPROJECT_FIGHT_H
#define GAMEPROJECT_FIGHT_H

#include "../Squads/HeroSquad.h"
#include "../Squads/MonsterSquad.h"

#include "../KEYBOARD_SYMBOLS.h"

//class Fight implements the fight between a team of heroes and a team of monsters(enemies)

class Fight {

private:

    HeroSquad* heroes = nullptr;

    MonsterSquad* enemies = nullptr;

    void displayStats() const;

    //function returning random monster or nullptr if monster avoids attack
    Monster* attackRandomMonster() const;

    //function returning random hero or nullptr if hero avoids attack
    Hero* attackRandomHero() const;

    //attack function between two creatures, one attacks and the other receive damage
    static void attack(LivingCreature* attacker, LivingCreature* victim);

    //function implements spell cast of hero on a monster
    static void spellAttack(Hero* hero, Monster* monster);


public:

    Fight(HeroSquad* heroes, MonsterSquad* enemies)
    :heroes(heroes), enemies(enemies){
        std::cout << "Fight Begins..." << std::endl;
    }

    ~Fight() = default;

    static bool begin();

    bool isNotOver() const;

    bool playerTurn();

    void enemiesTurn();

};


#endif //GAMEPROJECT_FIGHT_H