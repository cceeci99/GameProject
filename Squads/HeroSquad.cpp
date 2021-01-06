#include "HeroSquad.h"


void HeroSquad::print() const {
    std::cout << "Squad: ";
    for (int i=0; i<teammates; i++){
        std::cout << heroes[i]->getName() << ", ";
    }
    std::cout << std::endl;
}


void HeroSquad::printStats() const {
    for(int i=0; i<teammates; i++){
        heroes[i]->print();
    }
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
    int totalHealth = 0;
    for(int i=0; i<teammates; i++){
        totalHealth += heroes[i]->getHealth();
    }

    return totalHealth==0;
}


void HeroSquad::regeneration() {
    for(int i=0; i<teammates; i++){
        heroes[i]->regeneration();
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


void HeroSquad::openInventory() {
    for (int i=0; i<teammates; i++){
        std::cout << "Do you want to open inventory for hero: " << heroes[i]->getName() << " ? Y/N" << std::endl;

        char answer;
        std::cin >> answer;

        if ( answer == 'Y' || answer == 'y' ) {
            heroes[i]->checkInventory();
        }
    }
}