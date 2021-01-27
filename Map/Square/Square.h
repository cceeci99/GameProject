
#ifndef GAMEPROJECT_SQUARE_H
#define GAMEPROJECT_SQUARE_H


class HeroSquad;    //forwarding class


//type of squares is enumeration for simplicity of the current game
enum SquareType{nonAccessible, market, common};

class Square {

private:
    SquareType type;
    int x, y;

    HeroSquad* squad = nullptr;

public:

    Square(int x, int y, SquareType type)
    : x(x), y(y), type(type){}

    ~Square() = default;

    int getX() const;
    int getY() const;

    SquareType getType() const;

    HeroSquad* getSquad() const;

    void setSquad(HeroSquad* heroSquad);

};


#endif //GAMEPROJECT_SQUARE_H