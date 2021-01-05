
#ifndef GAMEPROJECT_GAME_H
#define GAMEPROJECT_GAME_H

#include "Map/Grid/Grid.h"
#include "MarketPlace/Market.h"

#include "Squads/HeroSquad.h"
#include "Squads/MonsterSquad.h"

#include "Creatures/Heroes/Warrior.h"
#include "Creatures/Heroes/Paladin.h"
#include "Creatures/Heroes/Sorcerer.h"
#include "Creatures/Monsters/Dragon.h"
#include "Creatures/Monsters/ExoSkeleton.h"
#include "Creatures/Monsters/Spirit.h"


#define MAX_TEAMMATES 3     //max number of heroes per squad


class Game {

private:

    Grid* map = nullptr;            //a game consists of a map in a form of a grid(NxN array)

    Market* marketPlace = nullptr;  //a game has one marketPlace

    HeroSquad* squad = nullptr;     //a game has one squad consisting of (1-3) heroes

public:

    //create game
    Game();

    //finish game and delete it
    ~Game();

    //final function that is starting the game for the player
    void play();

    //function to create a squad of heroes for the player, the number of mobs is given from player
    void createTeam(int n);

    //function to create the map of a game with some pattern for the squares of the grid, size will be initialized from us
    void createMap(int size);

    //function to fill the market with some items and spells, before the player starts the game
    void fillMarket(const std::vector<Item*>& items, const std::vector<Spell*>& spells);

    //function to make an monster squad for battle with heroes, monsters are made randomly, at same level of heroes
    MonsterSquad* createMonsters();

};


#endif //GAMEPROJECT_GAME_H