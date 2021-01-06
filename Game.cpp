#include "Game.h"
#include "Fight.h"


void Game::createMap(int size) {
    map = new Grid(size);
}


void Game::fillMarket(const std::vector<Item *> &items, const std::vector<Spell *> &spells) {
    marketPlace = new Market();

    for(Item* i: items){
        marketPlace->addItem(i);
    }
    for(Spell* s: spells){
        marketPlace->addSpell(s);
    }
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
    int size = (int)random() % 5 + 1;

    MonsterSquad* monsterSquad = new MonsterSquad(size);

    int averageLevel = 0;
    for(int i=0; i<squad->getSize(); i++){
        averageLevel += squad->getHero(i)->getLevel();
    }
    averageLevel = averageLevel/squad->getSize();

    for(int i = 0; i < size; i++)
    {
        int MonsterType = (int) random() % 3 + 1; //[1, 3]

        Monster *monster = nullptr;

        switch (MonsterType)
        {
            case dragon:
                monster = new Dragon("sjuf", averageLevel);
                break;
            case exoskeleton:
                monster = new ExoSkeleton("fef", averageLevel);
                break;
            case spirit:
                monster = new Spirit("fgerge", averageLevel);
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

    squad->printStats();

    std::cout << "Are you ready to begin..." << std::endl;
    std::cout << "Move your heroes by using keys (w, a, s, d) for up, left, down and right" << std::endl;
    std::cout << "You can see map by pressing (m) whenever you want" << std::endl;
    std::cout << "You can quit game by pressing (q) whenever you want" << std::endl;
    std::cout << "You can check inventory of your heroes by pressing (i)" << std::endl;
    std::cout << "You can check your heroes status by pressing (c)" << std::endl;


    Square* current = map->getSquare(0, 0);
    squad->move(current);

    bool validButton = true;

    std::cout << "Start moving your heroes..." << std::endl;

    while(true)
    {
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
                squad->printStats();
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

                        if(answer == 'Y' || answer == 'y')
                            marketPlace->open(squad->getHero(i));
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

                    MonsterSquad* monsterSquad = createEnemies();  //call function to create the monsters for fight

                    Fight* fight = new Fight(squad, monsterSquad);  //create new fight

                    int round = 1;
                    while (fight->isNotOver())
                    {
                        fight->battle(round);            //where fight is implemented...
                        round++;
                    }

                    if (squad->defeated())
                    {
                        squad->revive();

                        current->setSquad(nullptr);
                        squad->move(map->getSquare(0,0));   //move heroes at start point of map because they died

                        for (int i=0; i<squad->getSize(); i++){
                            squad->getHero(i)->looseMoney();
                        }
                    }
                    else
                    {
                        //if some hero of the squad is defeated then revive him, with half of his hp and mp
                        for(int i=0; i<squad->getSize(); i++)
                        {
                            if (squad->getHero(i)->dead()){
                                squad->getHero(i)->revive();
                            }
                        }

                        //get XP and money
                        for(int i=0; i<squad->getSize(); i++)
                        {
                            //create formula for experience and money earn...
                            int xp = ((squad->getHero(i)->getLevel())*2 + 5)/monsterSquad->getSize();
                            int money = (squad->getHero(i)->getLevel()*100 + 50)/monsterSquad->getSize();
                            //

                            squad->getHero(i)->addExperience(xp);
                            squad->getHero(i)->earnMoney(money);
                        }
                    }
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