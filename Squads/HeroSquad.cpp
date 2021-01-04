#include "HeroSquad.h"

HeroSquad::HeroSquad(int teammates) {
    //allocate memory for number of mobs which will be given by the user
    squad = new Hero*[teammates];
    this->teammates = teammates;
}

HeroSquad::~HeroSquad() {
    for(int i=0; i<teammates; i++)
        delete squad[i];

    delete[] squad;
}

void HeroSquad::print() const {
    std::cout << "Squad: ";
    for (int i=0; i<teammates; i++){
        std::cout << squad[i]->getName() << ", ";
    }
    std::cout << std::endl;
}

void HeroSquad::setHero(Hero *hero) {
    for(int i=0; i<teammates; i++)
    {
        if ( squad[i] == nullptr )
        {
            squad[i] = hero;
            return;
        }
    }
}

Hero *HeroSquad::getHero(int pos) const {
    if ( pos >= teammates )
        return nullptr;

    return squad[pos];
}

Hero **HeroSquad::getSquad() const {
    return squad;
}

void HeroSquad::move(Square *square) {
    square->setSquad(this);
}

bool HeroSquad::wiped() const {
    int totalHealth = 0;
    for(int i=0; i<teammates; i++){
        totalHealth += squad[i]->getHealth();
    }

    return totalHealth==0;
}

void HeroSquad::regeneration() {
    for(int i=0; i<teammates; i++){
        squad[i]->regeneration();
    }
}

int HeroSquad::getSize() const {
    return teammates;
}
