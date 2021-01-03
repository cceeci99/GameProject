#include <iostream>
#include "Creatures/Heroes/Warrior.h"
#include "Items/Armor.h"
#include "Spells/FireSpell.h"
#include "Spells/IceSpell.h"
#include "MarketPlace/Market.h"
#include "Map/Grid/Grid.h"

#define MAX_TEAMMATES 3

int main(int args, char* argv[]) {
    //Grid creation
    Grid* map = new Grid(5);

    //Items creation
    Item* armor = new Armor("Emblem", 122, 1, 450);
    Item* armor1 = new Armor("hat", 50, 1, 25);
    Item* weapon = new Weapon("axe", 145, 1, 420, true);
    Item* weapon1 = new Weapon("sword", 100, 1, 200, false);
    Item* potion = new Potion("Antidote", 45, 1, Health, 101);

    //Spells creation
    Spell* spell = new FireSpell("inferno", 45, 1, 110, Range::getRandomRange(100, 500), 150);
    Spell* spell1 = new IceSpell("iceball", 50, 1, 1100, Range::getRandomRange(500, 1000), 80);

    //Market creation
    Market marketPlace;
    marketPlace.addItem(armor);
    marketPlace.addItem(armor1);
    marketPlace.addItem(weapon);
    marketPlace.addItem(weapon1);
    marketPlace.addItem(potion);
    marketPlace.addSpell(spell);
    marketPlace.addSpell(spell1);

    //Heroes creation
    Hero* warrior = new Warrior("Kratos");

    //Game
    Square* current = map->getSquare(0, 0);
    current->setHero(warrior);

    bool quit = false;
    bool validButton = true;
    bool justDisplay = false;

    while(!quit)
    {
        std::cout << "Choose where do you want to go" << std::endl;

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
                quit = true;
                std::cout << "Quit game..." << std::endl;
                break;
            case 'm':
                map->displayMap();
                justDisplay = true;
                break;
            default:
                std::cout << "Please enter a valid button" << std::endl;
                validButton = false;
                break;
        }

        if(!validButton || quit || justDisplay)
        {
            validButton = true;
            justDisplay = false;
            continue;
        }

        if(!map->outOfBounds(x1, y1))
        {
            Square* next = map->getSquare(x1, y1);
            if(next->getType() == nonAccessible)
            {
                std::cout << "The Square you want to enter is no accessible" << std::endl;
                std::cout << "Please, go to another direction" << std::endl;
            }
            else
            {
                current->move(next);
                current = next;

                if(next->getType() == common)
                {
                    std::cout << "You have entered a common square" << std::endl;

                    //if(...)
                        //attack()
                }
                else
                {
                    std::cout << "You have entered a square with market" << std::endl;
                    std::cout << "Do you want to open market? Y/size" << std::endl;

                    char answer;
                    std::cin >> answer;

                    if(answer == 'y' || answer == 'Y')
                    {
                        std::array<Hero*, MAX_TEAMMATES> HeroSquad = current->getHeroSquad();

                        for(int i = 0; i < current->getSize(); i++)
                        {
                            std::cout << "Do you want to open market for " << HeroSquad[i]->getName() << "? Y/N" << std::endl;

                            std::cin >> answer;

                            if(answer == 'Y' || answer == 'y') {
                                marketPlace.open(HeroSquad[i]);
                            }
                        }
                    }
                }

                std::cout << "Do you want to check inventory? Y/N" << std::endl;

                char answer;
                std::cin >> answer;

                if(answer == 'Y' || answer == 'y')
                {
                    std::array<Hero*, MAX_TEAMMATES> HeroSquad = current->getHeroSquad();

                    for(int i = 0; i < current->getSize(); i++)
                    {
                        std::cout << "Do you want to check inventory for " << HeroSquad[i]->getName() << "? Y/N" << std::endl;
                        std::cin >> answer;
                        if(answer == 'Y' || answer == 'y') {
                            HeroSquad[i]->checkInventory();
                        }
                    }
                }
            }   
        }
        else
        {
            std::cout << "The square you want to go is out of bound" << std::endl;
            std::cout << "Please, go to another direction" << std::endl;
        }

    }

    delete armor1;
    delete weapon1;
    delete spell;
    delete spell1;
    delete potion;
    delete weapon;
    delete armor;
    delete warrior;

    delete map;
    return 0;
}
