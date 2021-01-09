#include "Game.h"
#include "Fight.h"
#include "Spells/FireSpell.h"
#include "Spells/IceSpell.h"
#include "Spells/LightingSpell.h"


std::string names[6] = {"a","b","c","d","e","z",};

void Game::createMap(int size) {
    map = new Grid(size);
}


void Game::createMarket() {
    marketPlace = new Market();
/*
    //create some items and spells.
    Armor* armor1 = new Armor("name1", 150, 1, 100);
    Armor* armor2 = new Armor("name2", 250, 3, 200);


    Weapon* weapon1 = new Weapon("name1", 200, 1, 50, true);
    Weapon* weapon2 = new Weapon("name2", 300, 3, 100, false);


    //
    Potion* potion1 = new Potion("name1", 150, 1, Health, 75);

     */

    Item* armor = new Armor("Emblem", 100, 1, 70);
    Item* armor1 = new Armor("hat", 100, 1, 55);
    Item* weapon = new Weapon("axe", 100, 1, 100, true);
    Item* weapon1 = new Weapon("sword", 100, 1, 80, false);
    Item* potion = new Potion("Antidote", 100, 1, Health, 55);

    marketPlace->addItem(armor);
    marketPlace->addItem(armor1);
    marketPlace->addItem(weapon);
    marketPlace->addItem(weapon1);
    marketPlace->addItem(potion);

    Spell* spell = new FireSpell("inferno", 100, 1, 100, Range::getRandomRange(100, 300), 50);
    Spell* spell1 = new IceSpell("frost", 100, 1, 100, Range::getRandomRange(200, 250), 80);
    Spell* spell2 = new LightingSpell("zeus", 100, 1, 100, Range::getRandomRange(100, 200), 5);

    marketPlace->addSpell(spell);
    marketPlace->addSpell(spell1);
    marketPlace->addSpell(spell2);

}


void Game::createTeam(int n) {
    std::cout << "Creating a heroes of " << n << " heroes" << std::endl;
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


MonsterSquad *Game::createEnemies() {
    int size = (int)random() % 3 + 1;

    MonsterSquad* monsterSquad = new MonsterSquad(size);

    int averageLevel = 0;
    for(int i=0; i<squad->getSize(); i++){
        averageLevel += squad->getHero(i)->getLevel();
    }
    averageLevel = averageLevel/squad->getSize();

    std::vector<std::string> usedNames;

    for(int i = 0; i < size; i++)
    {
        int MonsterType = (int) random() % 3 + 1; //[1, 3]

        Monster *monster = nullptr;

        std::string name;
        while (true)
        {
            int r = (int)random() % 6;
            bool found = false;
            for (auto & usedName : usedNames)
            {
                if (names[r] == usedName)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                usedNames.push_back(names[r]);
                name = names[r];
                break;
            }
        }

        switch (MonsterType)
        {
            case dragon:
                monster = new Dragon(name, averageLevel);
                break;
            case exoskeleton:
                monster = new ExoSkeleton(name, averageLevel);
                break;
            case spirit:
                monster = new Spirit(name, averageLevel);
                break;
            default:
                break;
        }

        monsterSquad->setMonster(monster);
    }

    return monsterSquad;
}


void Game::play() {
    std::cout << "Welcome to our game" << std::endl;
    std::cout << "Please create your Hero Squad  of (1-3) heroes" << std::endl;


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

    squad->print();

    std::cout << "Are you ready to begin..." << std::endl;
    std::cout << "Move your heroes by using keys (w, a, s, d) for up, left, down and right" << std::endl;
    std::cout << "You can see map by pressing (m) whenever you want" << std::endl;
    std::cout << "You can quit game by pressing (q) whenever you want" << std::endl;
    std::cout << "You can check inventory of your heroes by pressing (i) and quit inventory by pressing zero(0)" << std::endl;
    std::cout << "You can check your heroes status by pressing (c)" << std::endl;


    Square* current = map->getSquare(0, 0);
    squad->move(current);

    bool validButton = true;

    std::cout << "Start moving your heroes..." << std::endl;

    while(true)
    {
        std::cout << "Make your move" << std::endl;
        char button;
        std::cin >> button;

        unsigned int x, y;
        x = current->getX();
        y = current->getY();

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
                std::cout << "Quit Game... Bye!" << std::endl;
                return;
            case 'm':
                map->displayMap();
                continue;
            case 'c':
                std::cout << "Your Heroes: " << std::endl;
                squad->print();
                continue;
            case 'i':
                squad->openInventory();
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
            Square* next = map->getSquare(x1, y1);

            if(next->getType() == nonAccessible)
            {
                std::cout << "The Square you want to enter is no accessible" << std::endl;
                std::cout << "Please, go to another direction" << std::endl;
                continue;
            }
            else if (next->getType() == market)
            {
                current->setSquad(nullptr);
                squad->move(next);
                current = map->getSquare(x1, y1);

                std::cout << "You entered a marketPlace do you want to open market? Y/N" << std::endl;
                char answer;
                std::cin >> answer;

                if ( answer == 'y' || answer == 'Y')
                {
                    for(int i=0; i<squad->getSize(); i++)
                    {
                        std::cout << "Do you want to open market for " << squad->getHero(i)->getName() << "? Y/N" << std::endl;

                        std::cin >> answer;

                        if(answer == 'Y' || answer == 'y') {
                            marketPlace->open(squad->getHero(i));
                        }
                        else
                            continue;
                    }
                }
                else
                {
                    std::cout << "You are not opening market, you can check your inventory or continue moving your heroes" << std::endl;
                    continue;
                }
            }
            else
            {
                current->setSquad(nullptr);
                squad->move(next);

                std::cout << "You have entered a common square" << std::endl;

                //a probability function for starting a fight
                if ( Fight::begin() )
                {
                    squad->setSquadStats();

                    MonsterSquad* enemies = createEnemies();  //call function to create the monsters for fight

                    Fight* fight = new Fight(squad, enemies);  //create new fight

                    int round = 1;

                    std::cout << "Fight Begins..." << std::endl;
                    while (fight->isNotOver())
                    {
                        std::cout << "Round: " << round << std::endl;

                        std::cout << "Your Turn" << std::endl;
                        if ( !fight->playerTurn() )
                            quit();

                        if ( enemies->defeated() )
                            break;

                        std::cout << "Enemies Turn" << std::endl;
                        fight->enemiesTurn();

                        //deal with active spells on monsters
                        for (int i=0; i<enemies->getSize(); i++)
                        {
                            Monster* mob = enemies->getMonster(i);

                            mob->reduceSpellsRound();       //reduce round
                            mob->checkExpiredSpells();      //check if some spell is expired and must be disabled
                        }

                        //regenerate stats of both heroes and enemies
                        squad->regeneration();
                        enemies->regeneration();

                        round++;
                    }

                    if (squad->defeated())
                    {
                        std::cout << "DEFEATED!!!" << std::endl;
                        squad->revive();

                        current->setSquad(nullptr);
                        squad->move(map->getSquare(0,0));   //move heroes at start point of map because they died

                        for (int i=0; i<squad->getSize(); i++){
                            squad->getHero(i)->looseMoney();            //heroes loose half of their money
                        }
                    }
                    else
                    {
                        std::cout << "VICTORYY!!" << std::endl;
                        //if some hero of the squad is defeated then revive him, with half of his hp and mp
                        for(int i=0; i<squad->getSize(); i++)
                        {
                            if (squad->getHero(i)->dead())
                            {
                                std::cout << "Reviving: " << squad->getHero(i)->getName() << std::endl;
                                squad->getHero(i)->revive();
                            }
                        }

                        //get XP and money
                        for(int i=0; i<squad->getSize(); i++)
                        {
                            //create formula for experience and money earn...
                            int xp = ((squad->getHero(i)->getLevel())*2 + 3)*enemies->getSize();
                            squad->getHero(i)->addExperience(xp);
                            std::cout << "+ " << xp << "xp" << std::endl;


                            int money = (squad->getHero(i)->getLevel()*50)*enemies->getSize();
                            squad->getHero(i)->earnMoney(money);
                            std::cout << "+ " << money << "money" << std::endl;
                        }
                    }

                    delete fight;
                }
                else
                {
                    std::cout << "No fight, you can check your inventory or continue moving your heroes" << std::endl;
                    continue;
                }
            }
        }
    }
}