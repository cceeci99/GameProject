
#ifndef GAMEPROJECT_HEROSQUAD_H
#define GAMEPROJECT_HEROSQUAD_H

#include "../KEYBOARD_SYMBOLS.h"

#include "../Creatures/Heroes/Hero.h"
#include "../Map/Square/Square.h"

class HeroSquad {

private:

    Hero** heroes;
    int teammates=0;

public:

    HeroSquad(int size);

    ~HeroSquad();

    void print() const;

    int getSize() const;

    Hero* getHero(int pos) const;
    void setHero(Hero* hero);

    bool defeated() const;
    void regeneration();
    void revive();

    void move(Square* square);

    bool checkInventory();

};


#endif //GAMEPROJECT_HEROSQUAD_H
