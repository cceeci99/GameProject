#include "HeroSquad.h"

HeroSquad::HeroSquad(int n) {

    heroes = new Hero*[n];

    for (int i = 0; i < n; i++)
    {
        heroes[i] = nullptr;
    }

    teammates = n;
}


HeroSquad::~HeroSquad() {

    for(int i=0; i < teammates; i++)
    {
        if (heroes[i] != nullptr)
        {
            delete heroes[i];
        }
    }

    delete[] heroes;
}


void HeroSquad::print() const {

    for(int i = 0; i < teammates; i++)
    {
        if (!heroes[i]->dead())
        {
            std::cout << i+1 << ")";
            heroes[i]->print();
        }
    }

    std::cout << std::endl;
}


int HeroSquad::getSize() const {
    return teammates;
}


Hero *HeroSquad::getHero(int pos) const {

    if (pos >= teammates)
        return nullptr;

    return heroes[pos];
}


void HeroSquad::setHero(Hero *hero) {

    for( int i = 0; i < teammates; i++ )
    {
        if ( heroes[i] == nullptr )
        {
            heroes[i] = hero;
            return;
        }
    }
}


bool HeroSquad::defeated() const {

    int total = 0;

    for(int i = 0; i < teammates; i++)
    {
        if (heroes[i]->dead())
        {
            total++;
        }
    }

    return (total == teammates);
}


void HeroSquad::regeneration() {

    for(int i = 0; i < teammates; i++)
    {
        heroes[i]->regenerate();
    }
}


void HeroSquad::revive() {

    for(int i = 0; i < teammates; i++)
    {
        heroes[i]->revive();
    }
}


void HeroSquad::move(Square *square) {
    square->setSquad(this);
}


bool HeroSquad::checkInventory() {

    for (int i = 0; i < teammates; i++)
    {
        std::cout << "Do you want to check inventory for hero: " << heroes[i]->getName() << " ? Y/N" << std::endl;

        char answer;
        std::cin >> answer;

        while ( answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n' && answer != 'Q' && answer != 'q')
        {
            std::cout << "Invalid input please try again" << std::endl;
            std::cin >> answer;
        }

        if (answer == 'Y' || answer == 'y')
        {
            heroes[i]->checkInventory();
        }
        else if (answer == 'Q' || answer == 'q')
        {
            return false;
        }
    }

    return true;
}