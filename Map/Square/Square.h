
#ifndef GAMEPROJECT_SQUARE_H
#define GAMEPROJECT_SQUARE_H

class HeroSquad;

enum SquareType{nonAccessible, market, common};

class Square {

private:
    SquareType type;
    int x, y;

    HeroSquad* squad{};


public:

    Square(int x, int y, SquareType type)
    : x(x), y(y), type(type){}

    ~Square() = default;

    SquareType getType() const{
        return type;
    }

    int getX() const{
        return x;
    }
    int getY() const{
        return y;
    }

    HeroSquad* getSquad() const{
        return squad;
    }

    void setSquad(HeroSquad* heroSquad){
        squad = heroSquad;
    }

};


#endif //GAMEPROJECT_SQUARE_H
