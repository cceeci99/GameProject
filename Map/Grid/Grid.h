#include "../Square/Square.h"

#ifndef GAMEPROJECT_GRID_H
#define GAMEPROJECT_GRID_H


class Grid {

private:
    Square*** array;
    unsigned int size;

public:

    explicit Grid(int size);

    ~Grid();

    Square* getSquare(unsigned int x, unsigned int y) const;

    bool outOfBounds(unsigned int x, unsigned int y) const;

    void displayMap() const;

};


#endif //GAMEPROJECT_GRID_H
