
#ifndef GAMEPROJECT_GAME_H
#define GAMEPROJECT_GAME_H

#include "Map/Grid/Grid.h"
#include "MarketPlace/Market.h"

#include "Squads/HeroSquad.h"
#include "Squads/MonsterSquad.h"

#include "Creatures/Heroes/Warrior.h"
#include "Creatures/Heroes/Paladin.h"
#include "Creatures/Heroes/Sorcerer.h"


#define MAX_TEAMMATES 3     //max number of mobs in a squad


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

    //function to create the array of monsters for the game, before the player starts the game, monsters will be initialized by us
    void createMonsters(){
        // to implement
        // create array of monsters initialize them with some level and attributes(health, defence, dodge) , names from file
        // values of level, attributes from macros or some kind of algorithm

    }

    void fight(HeroSquad* heroSquad){
        std::cout << "Fight..." << std::endl;

        int size = heroSquad->getSize();

        //create MosterSquad
        MonsterSquad* monsterSquad = new MonsterSquad(size);

        for(int i = 0; i < size; i++)
        {
            Hero *hero = heroSquad->getHero(i);
            int level = hero->getLevel();
            int MonsterType = (int) random() % 3 + 1; //[1, 3]
            Monster *monster = nullptr;

            switch (MonsterType)
            {
                case dragon:
                    //monster = new Dragon("sjuf", level);
                    break;
                case exoskeleton:
                    //monster = new ExoSkeleton("fef", level);
                    break;
                case spirit:
                    //monster = new Spirit("fgerge" level);
                    break;
                default:
                    break;
            }

            monsterSquad->setMonster(monster);
        }

    //     unsigned int round = 1;
    //     while(true){
    //        if (HeroSquad.wiped() || MonsterSquad.wiped(){
    //             //...   
    //             break;
    //        }

    //         if(round % 2 == 1){ //Heroes' turn
    //             //...        
    //         }
    //         else{ //Monsters' turn
    //             //...
    //         }

    //         //REGENERATION
    //         HeroSquad.regeneration();
    //         MonsterSquad.regeneration();

    //         round++;
    //     }
    }

};


#endif //GAMEPROJECT_GAME_H

