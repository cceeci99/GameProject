#include "Game.h"
#include "Spells/FireSpell.h"
#include "Spells/IceSpell.h"
#include "Spells/LightingSpell.h"


std::string names[6] = {"a","b","c","d","e","z",};


void Game::quit() {
    delete this;
    exit(1);
}


Market* Game::createMarket() {
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

    Spell* spell = new FireSpell("inferno", 100, 1, 100,Range(100, 300), 50);
    Spell* spell1 = new IceSpell("frost", 100, 1, 100,Range(200, 250), 80);
    Spell* spell2 = new LightingSpell("zeus", 100, 1, 100,Range(100, 200), 5);

    marketPlace->addSpell(spell);
    marketPlace->addSpell(spell1);
    marketPlace->addSpell(spell2);

    return marketPlace;
}


void Game::createHeroes() {

    int n;
    while (true)
    {
        std::cin >> n;

        if ( n > MAX_TEAMMATES )
        {
            std::cout << "Please choose valid number of heroes" << std::endl;
            continue;
        }
        break;
    }

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

        Hero* hero = nullptr;
        switch(type)
        {
            case warrior:
                hero = new Warrior(name);
                break;
            case paladin:
                hero = new Paladin(name);
                break;
            case sorcerer:
                hero = new Sorcerer(name);
                break;
            default:
                break;
        }
        squad->setHero(hero);

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

    std::cout << "Please create your Hero Squad  of (1-3) heroes" << std::endl;
    createHeroes();

    std::cout << "Your Hero Squad is ready: " << std::endl;
    squad->print();

    std::cout << "Move your heroes by using keys (w, a, s, d) for up, left, down and right" << std::endl;
    std::cout << "You can see map by pressing (m) whenever you want" << std::endl;
    std::cout << "You can quit game by pressing (q) whenever you want" << std::endl;
    std::cout << "You can check inventory of your heroes by pressing (i) and quit inventory by pressing zero(0)" << std::endl;
    std::cout << "You can check your heroes status by pressing (c)" << std::endl;


    Square* current = map->getSquare(0, 0);
    squad->move(current);

    enterMarket();

    bool validButton = true;

    while(true)
    {
        std::cout << "Move your heroes" << std::endl;
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

        if ( !validButton ){
            std::cout << "Please enter a valid button" << std::endl;
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
                std::cout << "Non-Accessible square, please go to another direction" << std::endl;
                continue;
            }
            else if (next->getType() == market)
            {
                current->setSquad(nullptr);
                squad->move(next);

                enterMarket();
            }
            else
            {
                current->setSquad(nullptr);
                squad->move(next);

                enterCommon();
            }

            current = map->getSquare(x1, y1);
        }
    }
}


void Game::enterMarket() {
    std::cout << "You have entered a marketPlace do you want to open market? Y/N" << std::endl;

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
        }
    }

}

void Game::enterCommon() {
    if (Fight::begin())
    {
        std::cout << "Fight Begins..." << std::endl;

        squad->setSquadStats();

        MonsterSquad *enemies = createEnemies();

        Fight *fight = new Fight(squad, enemies);

        int round = 1;

        while (fight->isNotOver())
        {
            std::cout << "Round: " << round << std::endl;

            std::cout << "Your Turn" << std::endl;
            if (!fight->playerTurn()) {
                quit();
            }

            if (enemies->defeated())
                break;

            std::cout << "Enemies Turn" << std::endl;
            fight->enemiesTurn();

            //reduce active spells on each monster
            enemies->unchargeActiveSpells();

            //regenerate stats of both heroes and enemies
            squad->regeneration();
            enemies->regeneration();

            round++;
        }

        if (squad->defeated())
        {
            std::cout << "DEFEATED!" << std::endl;
            defeat();
        }
        else
        {
            std::cout << "VICTORY!" << std::endl;
            victory(enemies->getSize());
        }

        delete fight;
    }
}

void Game::victory(int monstersDefeated) {
    for (int i = 0; i < squad->getSize(); i++)
    {
        Hero* hero = squad->getHero(i);

        if (hero->dead()){
            hero->revive();
        }
    }

    for (int i = 0; i < squad->getSize(); i++)
    {
        Hero* hero = squad->getHero(i);
        int level = hero->getLevel();

        int xp = (level * 2 + 3) * monstersDefeated;
        hero->addExperience(xp);
        std::cout << "+ " << xp << "xp" << std::endl;


        int money = (level*50) * monstersDefeated;
        hero->earnMoney(money);
        std::cout << "+ " << money << "money" << std::endl;
    }
}

void Game::defeat() {
    squad->revive();

    for (int i = 0; i < squad->getSize(); i++)
    {
        Hero* hero = squad->getHero(i);
        hero->looseMoney();
    }
}