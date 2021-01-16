
#ifndef GAMEPROJECT_GRID_H
#define GAMEPROJECT_GRID_H

#include "../Square/Square.h"
#include "../../Squads/HeroSquad.h"


class Grid {

private:
    Square*** array;
    const int size;

public:

    Grid(int size);

    ~Grid();

    Square* getSquare(unsigned int x, unsigned int y) const;

    bool outOfBounds(unsigned int x, unsigned int y) const;

    void displayMap() const;

};


#endif //GAMEPROJECT_GRID_H