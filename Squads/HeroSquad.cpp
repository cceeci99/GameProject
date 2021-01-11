#include "HeroSquad.h"


void HeroSquad::print() const {
    for(int i=0; i<teammates; i++)
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
    if ( pos >= teammates )
        return nullptr;

    return heroes[pos];
}


void HeroSquad::setHero(Hero *hero) {
    for(int i=0; i<teammates; i++)
    {
        if (heroes[i] == nullptr )
        {
            heroes[i] = hero;
            return;
        }
    }
}


void HeroSquad::setSquadStats() {
    for (int i=0; i<teammates; i++){
        heroes[i]->setCurrentStats();
    }
}


bool HeroSquad::defeated() const {
    int total = 0;
    for(int i=0; i<teammates; i++)
    {
        if ( heroes[i]->dead() ) {
            total++;
        }
    }

    return total == teammates;
}


void HeroSquad::regeneration() {
    for(int i=0; i<teammates; i++){
        heroes[i]->regenerate();
    }
}


void HeroSquad::revive() {
    for(int i=0; i<teammates; i++){
        heroes[i]->revive();
    }
}


void HeroSquad::move(Square *square) {
    square->setSquad(this);
}


void HeroSquad::checkInventory() {
    for (int i=0; i<teammates; i++)
    {
        std::cout << "Do you want to check inventory for hero: " << heroes[i]->getName() << " ? Y/N" << std::endl;

        char answer;
        std::cin >> answer;

        if ( answer == 'Y' || answer == 'y' ) {
            heroes[i]->checkInventory();
        }
    }
}