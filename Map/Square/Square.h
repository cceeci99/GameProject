
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

    SquareType getType() const;

    int getX() const;
    int getY() const;

    HeroSquad* getSquad() const;
    void setSquad(HeroSquad* heroSquad);

};


#endif //GAMEPROJECT_SQUARE_H