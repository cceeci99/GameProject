#include "Grid.h"

Grid::Grid(int size) : size(size){

    array = new Square**[size];

    for(int i = 0; i < size; i++)
    {
        array[i] = new Square *[size];
    }

    for(int j = 0; j < size; j++)
    {
        if (j % 3 == 0)
        {
            array[0][j] = new Square(0, j, market);
        }
        else if(j % 5 == 0)
        {
            array[0][j] = new Square(0, j, nonAccessible);
        }
        else
        {
            array[0][j] = new Square(0, j, common);
        }
    }

    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if (j == 0)
            {
                SquareType type = array[i-1][size-1]->getType();
                array[i][j] = new Square(i, j, type);
            }
            else
            {
                SquareType type = array[i-1][j-1]->getType();
                array[i][j] = new Square(i, j, type);
            }
        }
    }
}


Grid::~Grid(){

    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            delete array[i][j];
        }
    }

    for(int i = 0; i < size; i++)
    {
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
                std::cout << "Your heroes are here!" << std::endl;
            }
        }
    }
}