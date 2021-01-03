#include "../Square/Square.h"

#ifndef GAMEPROJECT_GRID_H
#define GAMEPROJECT_GRID_H

class Grid {
    private:
        Square*** SquareArray;
        unsigned int N;
    public:
        Grid(int n);
        ~Grid();
        Square* getSquare(unsigned int x, unsigned int y) const;
        bool SqOutOfBounds(unsigned int x, unsigned int y) const;
        void displayMap() const;
}; 

#endif //GAMEPROJECT_GRID_H