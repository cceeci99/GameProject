
#ifndef GAMEPROJECT_HEROSQUAD_H
#define GAMEPROJECT_HEROSQUAD_H

#include "../Creatures/Heroes/Hero.h"
#include "../Map/Square/Square.h"


class HeroSquad {

private:

    Hero** squad;
    int teammates=0;

public:

    explicit HeroSquad(int teammates){
        //allocate memory for number of heroes which will be given by the user
        squad = new Hero*[teammates];
        this->teammates = teammates;
    }

    ~HeroSquad(){
        for(int i=0; i<teammates; i++)
            delete squad[i];

        delete[] squad;
    }

    void print() const;
    void printStats() const;

    int getSize() const;

    Hero* getHero(int pos) const;
    void setHero(Hero* hero);

    void setSquadStats();

    bool wiped() const;
    void regeneration();
    void revive();

    void move(Square* square);
    void openInventory();

};


#endif //GAMEPROJECT_HEROSQUAD_H
