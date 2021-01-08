#include "Grid.h"

Grid::Grid(int size) : size(size){
    array = new Square**[size];

    for(int i = 0; i < size; i++) {
        array[i] = new Square *[size];
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if (i%2 == 1){
                array[i][j] = new Square(i, j, market);
            }
            else{
                array[i][j] = new Square(i, j, common);
            }

            /*
            // to implement pattern for squares !!
            if(i % 3 == 0)
                array[i][j] = new Square(i, j, market);
            else if(i % 2 == 0)
                array[i][j] = new Square(i, j, common);
            else
                array[i][j] = new Square(i, j, nonAccessible); */
        }
    }
}

Grid::~Grid(){
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            delete array[i][j];
        }
    }

    for(int i = 0; i < size; i++) {
        delete[] array[i];
    }

    delete[] array;
}

Square* Grid::getSquare(unsigned int x, unsigned int y) const{
    return array[x][y];
}

bool Grid::outOfBounds (unsigned int x, unsigned int y) const {
    if(x >= size || x < 0 || y >= size || y < 0)
        return true;
    else
        return false;
}

void Grid::displayMap() const{
    std::cout << "Map consists of:" << std::endl;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            Square* square = array[i][j];
            std::cout << "(" << square->getX() << ", " << square->getY() << "):" << std::endl;

            std::cout << "This square ";
            switch (square->getType())
            {
                case common:
                    std::cout << "is common" << std::endl;
                    break;
                case nonAccessible:
                    std::cout << "is nonAccessible" << std::endl;
                    break;
                case market:
                    std::cout << "contains market" << std::endl;
                    break;
                default:
                    break;
            }

            if(square->getSquad() == nullptr)
            {
                std::cout << "--" << std::endl;
            }
            else
            {
                std::cout << "XX" << std::endl;
            }
        }
    }
}