#include "../../Creatures/Heroes/Hero.h"
#include <array>

#ifndef GAMEPROJECT_SQUARE_H
#define GAMEPROJECT_SQUARE_H

enum Status{nonAccesible, market, common};

using namespace std;

class Square{
    private:
        unsigned int x, y; //coordinates of square
        unsigned int size;
        array<Hero*, 3> HeroSquad;
        Status status;
    public:
        Square(unsigned int x1, unsigned int y1, Status stat);
        Status getStatus() const;
        unsigned int getX() const;
        unsigned int getY() const;
        unsigned int getSize() const;
        std::array<Hero*, 3> getHeroSquad() const;
        bool setHero(Hero* h);
        void move(Square* sq);
}; 

#endif //GAMEPROJECT_SQUARE_H