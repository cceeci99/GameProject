#include "HeroSquad.h"

HeroSquad::HeroSquad(int teammates) {
    //allocate memory for number of mobs which will be given by the user
    team = new Hero*[teammates];
    this->teammates = teammates;
}

HeroSquad::~HeroSquad() {
    for(int i=0; i<teammates; i++)
        delete team[i];

    delete[] team;
}

void HeroSquad::print() const {
    for (int i=0; i<teammates; i++){
        team[i]->print();
    }
}

void HeroSquad::setHero(Hero *hero) {
    for(int i=0; i<teammates; i++)
    {
        if ( team[i] == nullptr )
        {
            team[i] = hero;
            return;
        }
    }
}

Hero *HeroSquad::getHero(int pos) const {
    if ( pos >= teammates )
        return nullptr;

    return team[pos];
}

Hero **HeroSquad::getTeam() const {
    return team;
}

void HeroSquad::move(Square *square) {
    square->setSquad(this);
}

bool HeroSquad::wiped() const {
    int totalHealth = 0;
    for(int i=0; i<teammates; i++){
        totalHealth += team[i]->getHealth();
    }

    return totalHealth==0;
}

void HeroSquad::regeneration() {
    for(int i=0; i<teammates; i++){
        team[i]->regeneration();
    }
}
