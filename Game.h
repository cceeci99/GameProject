
#ifndef GAMEPROJECT_GAME_H
#define GAMEPROJECT_GAME_H

#include "Map/Grid/Grid.h"
#include "MarketPlace/Market.h"

#include "Squads/HeroSquad.h"
#include "Squads/MonsterSquad.h"

#include "Fight.h"

#include "Creatures/Heroes/Warrior.h"
#include "Creatures/Heroes/Paladin.h"
#include "Creatures/Heroes/Sorcerer.h"

#include "Creatures/Monsters/Dragon.h"
#include "Creatures/Monsters/ExoSkeleton.h"
#include "Creatures/Monsters/Spirit.h"

#define MAP_SIZE 8
#define MAX_TEAMMATES 3


class Game {

private:

    Grid* map = new Grid(MAP_SIZE);

    Market* marketPlace = createMarket();

    HeroSquad* squad = nullptr;

    void createHeroes();
    MonsterSquad* createEnemies();
    Market* createMarket();

    void quit();
    bool playerMove(Square* currentPos, unsigned int& x1, unsigned int& y1);

    void enterMarket();
    void enterCommon();

    void victory(int monstersDefeated);
    void defeat();


public:

    Game(){
        std::cout << "Welcome to our game!" << std::endl;
    }

    ~Game(){
        std::cout << "Quit Game... Bye" << std::endl;

        delete map;
        delete marketPlace;
        delete squad;
    }

    void play();

};


#endif //GAMEPROJECT_GAME_H