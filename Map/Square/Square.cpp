#include "Square.h"

Square::Square(unsigned int x, unsigned int y, SquareType type) : x(x), y(y), type(type), teammatesNumber(0){
    for(int i = 0; i < MAX_TEAMMATES; i++){
        HeroSquad[i] = nullptr;
    }
}

SquareType Square::getType() const{
    return type;
}

bool Square::setHero(Hero* hero){
    for(int i = 0; i < MAX_TEAMMATES; i++)
    {
        if(HeroSquad[i] ==  nullptr)
        {
            HeroSquad[i] = hero;
            teammatesNumber++;

            return true;
        }
    }

    return false;
}

void Square::move(Square* square){
    for(int i = 0; i < teammatesNumber; i++)
    {
        square->setHero(HeroSquad[i]);

        HeroSquad[i] = nullptr;
        teammatesNumber--;
    }
}

unsigned int Square::getX() const {
    return x;
}

unsigned int Square::getY() const {
    return y;
}

unsigned int Square::getSize() const{
    return teammatesNumber;
}

std::array<Hero*, MAX_TEAMMATES> Square::getHeroSquad() const {
    return HeroSquad;
}