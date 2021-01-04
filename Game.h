#include <iostream>

#include "Map/Grid/Grid.h"
#include "MarketPlace/Market.h"

#include "Creatures/Monsters/Monster.h"
#include "Creatures/Heroes/Hero.h"

#include "HeroSquad.h"
#include "MonsterSquad.h"
#include "Creatures/Heroes/Warrior.h"
#include "Creatures/Heroes/Paladin.h"
#include "Creatures/Heroes/Sorcerer.h"

#ifndef GAMEPROJECT_GAME_H
#define GAMEPROJECT_GAME_H

#define MAX_TEAMMATES 3     //max number of teammates in a squad
#define MAX_ENEMIES 100     //max number of monsters in the game


class Game {

private:

    Grid* map = nullptr;            //a game consists of a map in a form of a grid(NxN array)

    Market* marketPlace = nullptr;  //a game has one marketPlace

    Monster** monsters = new Monster*[MAX_ENEMIES];   //a game has one array of monsters

    HeroSquad* squad = nullptr;     //a game has one team consisting of (1-3) heroes

public:

    Game(){
        std::cout << "Our Game is created!" << std::endl;
    }

    //when finishing game delete all the elements of the game
    ~Game(){
        delete map;
        delete marketPlace;
        delete squad;
        delete[] monsters;
    }

    //function to create a team of heroes for the player, the number of teammates is given from player
    void createTeam(int n){
        std::cout << "Creating a team of " << n << " members" << std::endl;
        squad = new HeroSquad(n);

        std::cout << "Please choose name and type of each hero 1:warrior, 2:paladin, 3:sorcerer" << std::endl;

        int i=0;
        while (i < n)
        {
            std::cout << "Create your " << i+1 << " hero" << std::endl;

            std::string name;
            std::cout << "Choose name" << std::endl;
            std::cin >> name;

            int type;
            std::cout << "Choose type" << std::endl;
            std::cin >> type;

            Hero* hero;
            switch(type)
            {
                case warrior:
                    hero = new Warrior(name);
                    squad->setHero(hero);
                    break;
                case paladin:
                    hero = new Paladin(name);
                    squad->setHero(hero);
                    break;
                case sorcerer:
                    hero = new Sorcerer(name);
                    squad->setHero(hero);
                    break;
                default:
                    break;
            }
            i++;
        }

    }

    //function to create the map of a game with some pattern for the squares of the grid, size will be initialized from us
    void createMap(int size){
        map = new Grid(size);
        //

    }

    //function to fill the market with some items and spells, before the player starts the game
    void fillMarket(const std::vector<Item*>& items, const std::vector<Spell*>& spells){
        marketPlace = new Market();

        for(Item* i: items){
            marketPlace->addItem(i);
        }
        for(Spell* s: spells){
            marketPlace->addSpell(s);
        }
    }

    //function to create the array of monsters for the game, before the player starts the game, monsters will be initialized by us
    void createMonsters(std::string names[MAX_ENEMIES]){
        // to implement
        // create array of monsters initialize them with some level and attributes(health, defence, dodge) , names from file
        // values of level, attributes from macros or some kind of algorithm



    }


    //final function that is starting the game for the player
    void play(){
        std::cout << "Welcome to our game" << std::endl;
        std::cout << "Please create your Hero Squad  of (1-3) members" << std::endl;

        int n;
        while (true)
        {
            std::cin >> n;

            if ( n > MAX_TEAMMATES )
            {
                std::cout << "Please choose valid number of heroes" << std::endl;
                continue;
            }
            createTeam(n);
            break;
        }

        std::cout << "Your Hero Squad is ready: " << std::endl;
        //print HeroSquad for the player
        squad->print();

        std::cout << "Are you ready to begin..." << std::endl;
        std::cout << "Move your team by using keys (w, a, s, d) for up, left, down and right" << std::endl;
        std::cout << "You can see map by pressing (m) whenever you want" << std::endl;
        std::cout << "You can quit game by pressing (q) whenever you want" << std::endl;
        std::cout << "If your team gets in common square and don't get in fight, you can check inventory of your heroes by pressing (i)" << std::endl;
        std::cout << "Whenever you get involved in fight and it's your turn you can display stats of your team and enemies by pressing (t)" << std::endl;
        std::cout << "You can make normal attack by pressing (o), cast spell by pressing (l) or use potion by pressing (p)" << std::endl;


        Square* start = map->getSquare(0,0);
        squad->move(start);

        bool validButton = true;

        std::cout << "Start moving your team..." << std::endl;

        while(true)
        {
            char button;
            std::cin >> button;

            unsigned int x, y;
            x = start->getX();
            y = start->getY();

            unsigned int x1, y1;

            switch (button)
            {
                case 'w':
                    x1 = x + 1;
                    y1 = y;
                    break;
                case 's':
                    x1 = x - 1;
                    y1 = y;
                    break;
                case 'a':
                    x1 = x;
                    y1 = y - 1;
                    break;
                case 'd':
                    x1 = x;
                    y1 = y + 1;
                    break;
                case 'q':
                    quit();
                    break;
                case 'm':
                    map->displayMap();
                    continue;
                default:
                    validButton = false;
                    break;
            }

            if ( !validButton )
            {
                std::cout << "Please enter a valid button" << std::endl;
                continue;
            }

            if (map->outOfBounds(x1, y1))
            {
                std::cout << "You are going out of bounds please try again" << std::endl;
                continue;
            }
            else
            {
                start->setSquad(nullptr);
                Square* next = map->getSquare(x1, y1);
                squad->move(next);
              
                if(next->getType() == nonAccessible)
                {
                    std::cout << "The Square you want to enter is no accessible" << std::endl;
                    std::cout << "Please, go to another direction" << std::endl;
                    continue;
                }
                else if (next->getType() == market)
                {
                    std::cout << "You entered a marketPlace do you want to open market? Y/N" << std::endl;
                    char answer;
                    std::cin >> answer;

                    if ( answer == 'y' || answer == 'Y')
                    {
                        for(int i=0; i<squad->getSize(); i++)
                        {
                            std::cout << "Do you want to open market for " << squad->getHero(i)->getName() << "? Y/N" << std::endl;

                            std::cin >> answer;

                            if(answer == 'Y' || answer == 'y'){
                                marketPlace->open(squad->getHero(i));
                            }
                            else{
                                continue;
                            }
                        }
                        continue;
                    }
                    else
                    {
                        std::cout << "Bye..." << std::endl;
                        continue;
                    }
                }
                else
                {
                    std::cout << "You have entered a common square" << std::endl;

                    //if(...)
                        //attack()

                }
                break;
            }

        }

    }

    void figth(HeroSquad* herosquad){
        cout << "Fight..." << endl;

        int size = herosquad->getSize();
        //create MosterSquad
        MonsterSquad* monstersquad = new MonsterSquad(size);
        for(int i = 0; i < size; i++){
            Hero* hero = herosquad->getHero(i);
            int level = hero->getLevel();
            int MonsterType = rand % 3 +1; //[1, 3]
            Monster* monster;

            switch (MonsterType)
            {
            case Dragon:
                //monster = new Dragon("sjuf", level);
                break;
            case ExoSkeleton:
                //monster = new ExoSkeleton("fef", level);
                break;
            }
            case Spirit:
                //monster = new Spirit("fgerge" level);
                break;
            }

            monstersquad->setMonster(monster);
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

    static void quit(){
        std::cout << "Quit Game... Bye!" << std::endl;
        exit(0);
    }



};


#endif //GAMEPROJECT_GAME_H

