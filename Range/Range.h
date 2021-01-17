
#ifndef GAMEPROJECT_RANGE_H
#define GAMEPROJECT_RANGE_H

#include <iostream>


class Range {

private:
    int min;
    int max;

public:

    Range(int low, int high)
    : min(low), max(high){};

    ~Range() = default;

    void print() const;

    int getValue() const;

    int getMax() const;

    void reduceRange(int reduce);

};


#endif //GAMEPROJECT_RANGE_H