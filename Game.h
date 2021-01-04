#include <iostream>
#include "Map/Grid/Grid.h"
#include "MarketPlace/Market.h"
#include "Creatures/Monsters/Monster.h"
#include "Creatures/Heroes/Hero.h"

#ifndef GAMEPROJECT_GAME_H
#define GAMEPROJECT_GAME_H


#define MAX_ENEMIES 100

class Game {

private:

    Grid* map = nullptr;

    Market* marketPlace = nullptr;

    Monster** monsters = new Monster*[MAX_ENEMIES];



public:

    void createMap(int size){
        // create map with specified teammatesNumber
        // find some pattern for the squares
    }

    //to implement
    void fillMarket(Item** items, Spell* spells){
        // to implement
        // fill marketplace with some items and spells, with random names (from file) and values
    }

    void createMonsters(std::string names[MAX_ENEMIES]){
        // to implement
        // create array of monsters initialize them with some level and attributes(health, defence, dodge) , names from file
        // values of level, attributes from macros or some kind of algorithm
    }




    static void play(){
        std::cout << "Welcome to our game" << std::endl;
        std::cout << "Choose number of teammates for your Hero Squad(1-3)" << std::endl;

        int n;
        while (true)
        {
            std::cin >> n;

            if ( n > 3 )
            {
                std::cout << "Please choose valid number of heroes" << std::endl;
                continue;
            }
            break;
        }

        //create hero squad as an array of n heroes and put squad at start position of the map

        std::cout << "Please choose name and type of each hero" << std::endl;

        //create each hero

        std::cout << "Your Hero Squad is ready: " << std::endl;
        //print HeroSquad for the player


        std::cout << "Are you ready to begin..." << std::endl;
        std::cout << "Move your team by using keys (w, a, s, d) for up, left, down and right" << std::endl;
        std::cout << "You can see map by pressing (m) whenever you want" << std::endl;
        std::cout << "You can quit game by pressing (q) whenever you want" << std::endl;
        std::cout << "If your team gets in common square and don't get in fight, you can check inventory of your heroes by pressing (i)" << std::endl;
        std::cout << "Whenever you get involved in fight and it's your turn you can display stats of your team and enemies by pressing (t)" << std::endl;
        std::cout << "You can make normal attack by pressing (o), cast spell by pressing (l) or use potion by pressing (p)" << std::endl;

    }

    void figth(HeroSquad ){
        cout << "Fight..." << endl;

        int totalMonsters = rand() % 5 + 1; //[1, 5]
        //create MosterSquad
        unsigned int j = 0;
        for(int i = 0; i < totalMonsters; i++){
            unsigned int curLevel = HeroSquad[j]->getLevel(); 
            int MonsterType = rand % 3;
            
            switch (MonsterType)
            {
            case Dragon:
                //...
                break;
            case ExoSkeleton:
                //...
                break;
            }
            case Spirit:
                //...
                break;
            }

            j++;
            if(j >= sq->getSize())
                j = 0;
        }

        unsigned int round = 1;
        while(true){
           if (HeroSquad.wiped() || MonsterSquad.wiped(){
                //...   
                break;
           }

            if(round % 2 == 1){ //Heroes' turn
                //...        
            }
            else{ //Monsters' turn
                //...
            }

            //REGENERATION
            HeroSquad.regeneration();
            MonsterSquad.regeneration();

            round++;
        }
    }

    static void quit(){
        std::cout << "Quit Game... Bye!" << std::endl;
        exit(0);
    }


};


#endif //GAMEPROJECT_GAME_H
