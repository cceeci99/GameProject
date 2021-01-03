#include "Square.h"

Square::Square(unsigned int x1, unsigned int y1, Status stat) : x(x1), y(y1), status(stat), size(0){
    for(int i = 0; i < 3; i++)
        HeroSquad[i] = nullptr;
}

Status Square::getStatus() const{
    return status;
}

bool Square::setHero(Hero* h){
    for(int i = 0; i < 3; i++){
        if(HeroSquad[i] ==  nullptr){
            HeroSquad[i] = h;
            size++;
            return true;
        }
    }

    return false;
}

void Square::move(Square* sq){
    for(int i = 0; i < size; i++){
        sq->setHero(HeroSquad[i]);
        HeroSquad[i] = nullptr;
        size--;
    }
}

unsigned int Square::getX() const {
    return x;
}

unsigned int Square::getY() const {
    return y;
}

unsigned int Square::getSize() const{
    return size;
}

std::array<Hero*, 3> Square::getHeroSquad() const {
    return HeroSquad;
}