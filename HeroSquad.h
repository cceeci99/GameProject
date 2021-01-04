#include <iostream>
#include <array>

#include "Creatures/Heroes/Hero.h"
#include "Map/Square/Square.h"

#ifndef GAMEPROJECT_HEROSQUAD_H
#define GAMEPROJECT_HEROSQUAD_H


class HeroSquad {

private:

    Hero** team;
    int teammates=0;

public:

    explicit HeroSquad(int teammates){
        //allocate memory for number of teammates which will be given by the user
        team = new Hero*[teammates];
        this->teammates = teammates;
    }

    ~HeroSquad(){
        for(int i=0; i<teammates; i++)
            delete team[i];

        delete[] team;
    }

    int getSize() const{
        return teammates;
    }

    void print() const{
        for (int i=0; i<teammates; i++){
            team[i]->print();
        }
    }

    void setHero(Hero* hero){
        for(int i=0; i<teammates; i++)
        {
            if ( team[i] == nullptr )
            {
                team[i] = hero;
                return;
            }
        }
    }

    Hero* getHero(int pos) const{
        if ( pos >= teammates )
            return nullptr;

        return team[pos];
    }

    Hero** getTeam() const{
        return team;
    }

    void move(Square* square){
        square->setSquad(this);
    }

    bool wiped() const{
        int totalHealth = 0;
        for(int i=0; i<teammates; i++){
            totalHealth += team[i]->getHealth();
        }

        return totalHealth==0;
    }

    void regeneration(){
        for(int i=0; i<teammates; i++){
            team[i]->regeneration();
        }
    }


};


#endif //GAMEPROJECT_HEROSQUAD_H
