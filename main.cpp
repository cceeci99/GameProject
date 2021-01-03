#include <iostream>
#include "Creatures/Heroes/Warrior.h"
#include "Items/Armor.h"
#include "Spells/FireSpell.h"
#include "Spells/IceSpell.h"
#include "MarketPlace/Market.h"
#include "Map/Grid/Grid.h"

using namespace std;

int main(int args, char* argv[]) {
    //Grid creation
    Grid* g = new Grid(5);

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
    Square* sq = g->getSquare(0, 0);
    sq->setHero(warrior);
    bool quit = false;
    bool validButton = true;
    bool justDisplay = false;
    while(!quit){
        cout << "Choose where do you want to go" << std::endl;
        char button;
        std::cin >> button;
        unsigned int x, y;
        x = sq->getX();
        y = sq->getY();
        unsigned int x1, y1;

        switch (button){
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
            cout << "Quit game..." << std::endl;
            break;
        case 'm':
            g->displayMap();
            justDisplay = true;
            break;
        default:
            cout << "Please enter a valid button" << std::endl;
            validButton = false;
            break;
        }

        if(!validButton || quit || justDisplay){
            validButton = true;
            justDisplay = false;
            continue;
        }

        if(!g->SqOutOfBounds(x1, y1)){
            Square* SqToMove = g->getSquare(x1, y1);
            if(SqToMove->getStatus() == nonAccesible){
                cout << "The Square you want to enter is no accesible" << std::endl;
                cout << "Please, go to another direction" << std::endl;
            }
            else{
                sq->move(SqToMove);
                sq = SqToMove;
                if(SqToMove->getStatus() == common){
                    cout << "You have entered a common square" << std::endl;
                    //if(...)
                        //attack()
                }
                else{
                    cout << "You have enter a square with market" << std::endl;
                    cout << "Do you want to open market? Y/N" << std::endl;
                    char answer;
                    std::cin >> answer;
                    if(answer == 'y' || answer == 'Y'){
                        array<Hero*, 3> HeroSquad = sq->getHeroSquad();
                        for(int i = 0; i < sq->getSize(); i++){
                            cout << "Do you want to open market for " << HeroSquad[i]->getName() << "? Y/N" << std::endl;
                            std::cin >> answer;
                            if(answer == 'Y' || answer == 'y')
                                marketPlace.open(HeroSquad[i]);
                        }
                    }
                }
                cout << "Do you want to check inventory? Y/N" << std::endl;
                char answer;
                std::cin >> answer;
                if(answer == 'Y' || answer == 'y'){
                    array<Hero*, 3> HeroSquad = sq->getHeroSquad();
                    for(int i = 0; i < sq->getSize(); i++){
                        cout << "Do you want to check inventory for " << HeroSquad[i]->getName() << "? Y/N" << std::endl;
                        std::cin >> answer;
                        if(answer == 'Y' || answer == 'y')
                            HeroSquad[i]->checkInventory();
                    }
                }
            }   
        }
        else{
            cout << "The square you want to go is out of bound" << std::endl;
            cout << "Please, go to another direction" << std::endl;
        }
        //cout << "YOU ARE IN SQUARE WITH (x, y)=(" << sq->getX() << ", " << sq->getY() << ")" << std::endl;
    }

    warrior->checkInventory();

    warrior->usePotion();

    warrior->checkInventory();

    delete armor1;
    delete weapon1;
    delete spell;
    delete spell1;
    delete potion;
    delete weapon;
    delete armor;
    delete warrior;

    delete g;
    return 0;
}
