#include <iostream>

#include "../Creatures/Heroes/Hero.h"
#include "../Map/Square/Square.h"

#ifndef GAMEPROJECT_HEROSQUAD_H
#define GAMEPROJECT_HEROSQUAD_H


class HeroSquad {

private:

    Hero** team;
    int teammates=0;

public:

    explicit HeroSquad(int teammates);

    ~HeroSquad();

    int getSize() const{
        return teammates;
    }

    void print() const;

    void setHero(Hero* hero);

    Hero* getHero(int pos) const;

    Hero** getTeam() const;

    void move(Square* square);

    bool wiped() const;

    void regeneration();

};


#endif //GAMEPROJECT_HEROSQUAD_H
