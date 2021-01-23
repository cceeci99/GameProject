#include "Game.h"


Game::Game() {

    std::cout << "Welcome to our game!" << std::endl;

    map = new Grid(MAP_SIZE);
    marketPlace = createMarket();
}


Game::~Game() {

    std::cout << "Quit Game... Bye" << std::endl;

    delete map;
    delete marketPlace;
    delete squad;
}


Market* Game::createMarket() {

    marketPlace = new Market();

    Item* armor = new Armor("Emblem", 100, 1, 70);
    marketPlace->addItem(armor);
    armor = new Armor("Genji Shield", 150, 5, 110);
    marketPlace->addItem(armor);
    armor = new Armor("Rescue Shield", 200, 10, 200);
    marketPlace->addItem(armor);
    armor = new Armor("Gold Shield", 500, 15, 350);
    marketPlace->addItem(armor);

    Item* weapon = new Weapon("HeartBreaker", 100, 1, 100, true);
    marketPlace->addItem(weapon);
    weapon = new Weapon("Crystal Sword", 200, 4, 150, false);
    marketPlace->addItem(weapon);
    weapon = new Weapon("Full Metal Rod", 350, 8, 200, false);
    marketPlace->addItem(weapon);
    weapon = new Weapon("Darkness Staff", 450, 14, 350, true);
    marketPlace->addItem(weapon);

    Item* potion = new Potion("Antidote", 100, 1, 200, Health);
    marketPlace->addItem(potion);
    potion = new Potion("Mana Tonic", 180, 3, 250, Mana);
    marketPlace->addItem(potion);
    potion = new Potion("Power Distiller", 250, 7, 100, Strength);
    marketPlace->addItem(potion);
    potion = new Potion("Mega-Potion", 340, 12, 70, Dexterity);
    marketPlace->addItem(potion);
    potion = new Potion("Speed Distiller", 400, 15, 55, Agility);
    marketPlace->addItem(potion);


    Spell* spell = new FireSpell("Flame", 100, 1, 150, Range(100, 300), 50);
    marketPlace->addSpell(spell);
    spell = new IceSpell("Freeze", 150, 4, 300, Range(200, 350), 80);
    marketPlace->addSpell(spell);
    spell = new LightingSpell("Angel’s Mercy", 250, 8, 400, Range(250, 450), 5);
    marketPlace->addSpell(spell);
    spell = new FireSpell("Fireball", 350, 14, 500, Range(350, 550), 5);
    marketPlace->addSpell(spell);

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

    //random names for heroes
    std::string names[10] = {"Karontor","Memnor","Luthic","Merlin","Sixin",
                                    "Ilneval", "Kratos", "Eadro", "Skerrit", "Jubilex"};

    std::vector<std::string> usedNames;

    for(int i = 0; i < n; i++)
    {
        int HeroType = (int) random() % 3 + 1; //[1, 3]

        Hero *hero = nullptr;

        //check for duplicate names
        std::string name = getUnusedName(usedNames, names);

        switch (HeroType)
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
    }
}


MonsterSquad *Game::createEnemies() {

    //some random names for the monsters creation
    std::string names[10] = {"Abbathor","Arvoreen","Ehlonna","Heironeous","Pelor",
                                    "Urdlen", "Bahamut", "Orcus", "Vaprak", "Bahgtru"};

    int size = (int)random() % 3 + 1;   //create random from 1 to 3 monsters

    MonsterSquad* enemies = new MonsterSquad(size);

    int averageLevel = 0;

    for(int i = 0; i < squad->getSize(); i++)
    {
        averageLevel += squad->getHero(i)->getLevel();
    }

    averageLevel = averageLevel/squad->getSize();

    std::vector<std::string> usedNames;

    for(int i = 0; i < size; i++)
    {
        int MonsterType = (int) random() % 3 + 1; //[1, 3]

        Monster *monster = nullptr;

        std::string name = getUnusedName(usedNames, names);

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

        enemies->setMonster(monster);
    }

    return enemies;
}


void Game::play() {

    std::cout << "Please create your Hero Squad  of (1-3) heroes" << std::endl;
    createHeroes();

    std::cout << "Your Hero Squad is ready: " << std::endl;
    squad->print();

    std::cout << "Move your heroes by using keys (w, a, s, d) for up, left, down and right" << std::endl;
    std::cout << "You can see map by pressing (m)" << std::endl;
    std::cout << "You can quit game by pressing (q)" << std::endl;
    std::cout << "You can check inventory of your heroes by pressing (i)" << std::endl;
    std::cout << "You can check your heroes stats by pressing (c)\n" << std::endl;

    //heroes start at coordinates 0,0 of map which contains market
    Square* currentPos = map->getSquare(0, 0);
    squad->move(currentPos);

    if (!enterMarket())
        return;

    unsigned int x = -1;
    unsigned int y = -1;

    while(true)
    {
        unsigned int tempX = x;
        unsigned int tempY = y;

        if (!playerMove(currentPos, x, y))
            return;

        //check if player is at same coordinates
        if ( (x == -1 && y == -1) || (x == tempX && y == tempY) )
            continue;

        if (map->outOfBounds(x, y))
        {
            std::cout << "You are going out of bounds please try again" << std::endl;
        }
        else
        {
            Square* next = map->getSquare(x, y);

            if (next->getType() == nonAccessible)
            {
                std::cout << "Non-Accessible square, please go to another direction" << std::endl;
                continue;
            }
            else if (next->getType() == market)
            {
                currentPos->setSquad(nullptr);
                squad->move(next);

                if (!enterMarket())
                    return;
            }
            else
            {
                currentPos->setSquad(nullptr);
                squad->move(next);

                if (!enterCommon())
                    return;
            }

            currentPos = map->getSquare(x, y);
        }
    }
}


bool Game::playerMove(Square *currentPos, unsigned int &x1, unsigned int &y1) {

    unsigned int x = currentPos->getX();
    unsigned int y = currentPos->getY();

    std::cout << "Move your heroes" << std::endl;

    char button;
    std::cin >> button;

    switch (button)
    {
        case MOVE_UP:
            x1 = x + 1;
            y1 = y;
            break;
        case MOVE_DOWN:
            x1 = x - 1;
            y1 = y;
            break;
        case MOVE_LEFT:
            x1 = x;
            y1 = y - 1;
            break;
        case MOVE_RIGHT:
            x1 = x;
            y1 = y + 1;
            break;
        case SHOW_MAP:
            map->displayMap();
            break;
        case SHOW_STATS:
            std::cout << "Your Heroes: " << std::endl;
            squad->print();
            break;
        case OPEN_INVENTORY:
            if(!squad->checkInventory()){
                return false;           //if player quits game while checking inventory
            }
            break;
        case QUIT:
        case QUIT_:
            return false;
        default:
            std::cout << "Please enter a valid button" << std::endl;
            break;
    }

    return true;
}


bool Game::enterMarket() {

    std::cout << "You have entered a marketPlace do you want to open market? Y/N" << std::endl;

    char answer;
    std::cin >> answer;

    while ( answer != YES && answer != YES_ && answer != NO && answer != NO_ && answer != QUIT && answer != QUIT_)
    {
        std::cout << "Invalid input please try again" << std::endl;
        std::cin >> answer;
    }

    if (answer == YES || answer == YES_)
    {
        int i = 0;

        while ( i < squad->getSize() )
        {
            std::cout << "Do you want to open market for " << squad->getHero(i)->getName() << "? Y/N" << std::endl;

            std::cin >> answer;

            if (answer == YES || answer == YES_)
            {
                marketPlace->open(squad->getHero(i));
            }
            else if (answer == NO || answer == NO_)
            {
                i++;
                continue;
            }
            else if (answer == QUIT || answer == QUIT_)
            {
                return false;
            }
            else
            {
                std::cout << "Invalid input please try again" << std::endl;
                continue;
            }
            i++;
        }
    }
    else if (answer == QUIT || answer == QUIT_)
    {
        return false;
    }

    return true;
}


bool Game::enterCommon() {

    std::cout << "You have entered common square" << std::endl;

    if (!Fight::begin())
    {
        std::cout << "No monsters around..." << std::endl;
        return true;
    }


    //each time heroes get evolved in fight generate random monsters in a form of team to fight them
    MonsterSquad* enemies = createEnemies();

    Fight fight(squad, enemies);

    int round = 1;

    while (fight.isNotOver())
    {
        std::cout << "Round: " << round << std::endl;

        std::cout << "Your Turn" << std::endl;


        //if player want to quit game during the fight
        if (!fight.playerTurn())
        {
            delete enemies;
            return false;
        }

        if (enemies->defeated())
            break;

        std::cout << "Enemies Turn" << std::endl;
        fight.enemiesTurn();

        //reduce active spells on each monster
        enemies->unchargeActiveSpells();

        //regenerate stats of both heroes and enemies
        squad->regeneration();
        enemies->regeneration();

        round++;
    }

    if (squad->defeated())
    {
        std::cout << "YOU WERE DEFEATED!" << std::endl;
        defeat();
    }
    else
    {
        std::cout << "VICTORY!" << std::endl;
        victory(enemies->getSize());
    }

    delete enemies;

    return true;
}


void Game::victory(int monstersDefeated) {

    for (int i = 0; i < squad->getSize(); i++)
    {
        Hero* hero = squad->getHero(i);

        if (hero->dead())
        {
            hero->revive();
        }
    }

    for (int i = 0; i < squad->getSize(); i++)
    {
        Hero* hero = squad->getHero(i);

        int level = hero->getLevel();

        int xp = (level * 2 + 3) * monstersDefeated;
        int money = (level*50) * monstersDefeated;

        std::cout << hero->getName() << " + " << money << " money"  << " + " << xp << " xp " << "    ";

        hero->addExperience(xp);
        hero->earnMoney(money);
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


std::string Game::getUnusedName(std::vector<std::string> &usedNames, std::string *names) {

    while (true)
    {
        std::string name;
        int r = (int)random() % 10;
        bool found = false;

        for (int i = 0; i < usedNames.size(); i++)
        {
            if (names[r] == usedNames[i])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            usedNames.push_back(names[r]);
            name = names[r];
            return name;
        }
    }
}