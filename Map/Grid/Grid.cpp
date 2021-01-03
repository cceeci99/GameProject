#include "Grid.h"

Grid::Grid(int n) : N(n){
    SquareArray = new Square**[N];
    for(int i = 0; i < N; i++)
        SquareArray[i] = new Square*[N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i % 3 == 0){
                SquareArray[i][j] = new Square(i, j, nonAccesible);
            }
            else if(i % 2 == 0){
                SquareArray[i][j] = new Square(i, j, market);
            }
            else{
                SquareArray[i][j] = new Square(i, j, common);
            }
        }
    }
}

Grid::~Grid(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            delete SquareArray[i][j];
            
    for(int i = 0; i < N; i++)
        delete[] SquareArray[i];

    delete[] SquareArray;
}

Square* Grid::getSquare(unsigned int x, unsigned int y) const{
    return SquareArray[x][y];
}

bool Grid::SqOutOfBounds (unsigned int x, unsigned int y) const {
    if(x >= N || x < 0 || y >= N || y < 0)
        return true;
    else 
        return false;
}

void Grid::displayMap() const{
    cout << "Map consists of:" << std::endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Square* sq = SquareArray[i][j];
            cout << "Square with coordinates (" << sq->getX() << ", " << sq->getY() << "):" << std::endl;
            cout << "This square ";
            switch (sq->getStatus())
            {
            case common:
                cout << "is common" << endl;
                break;
            case nonAccesible:
                cout << "is nonAccessible" << endl;
                break;            
            case market:
                cout << "contains market" << endl;
                break;
            }  
            std::array<Hero*, 3> HeroSquad = sq->getHeroSquad();
            unsigned int size = sq->getSize();
            if(size == 0){
                cout << "No Hero exists in this square" << std::endl;
            }
            else{
                cout << "Heroes in this square are:" << std::endl;
                for(int k = 0; k < size; k++)
                    HeroSquad[k]->print();
            }
        }
    }
}