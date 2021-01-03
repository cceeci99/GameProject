#include <array>

#include "../../Creatures/Heroes/Hero.h"


#ifndef GAMEPROJECT_SQUARE_H
#define GAMEPROJECT_SQUARE_H

#define MAX_TEAMMATES 3

enum SquareType{nonAccessible, market, common};


class Square{

private:
    unsigned int x, y;                      //coordinates of square
    unsigned int teammatesNumber;

    std::array<Hero*, MAX_TEAMMATES> HeroSquad{};
    SquareType type;

public:

    Square(unsigned int x, unsigned int y, SquareType type);

    SquareType getType() const;

    unsigned int getX() const;

    unsigned int getY() const;

    unsigned int getSize() const;

    std::array<Hero*, MAX_TEAMMATES> getHeroSquad() const;

    bool setHero(Hero* h);

    void move(Square* sq);
}; 


#endif //GAMEPROJECT_SQUARE_H