#include <iostream>
#include <cstdlib>

#ifndef GAMEPROJECT_RANGE_H
#define GAMEPROJECT_RANGE_H


class Range {
public:
    int min;
    int max;

    Range(int low, int high): min(low), max(high){};
    ~Range() = default;

    int getValue() const{
        srand(time(nullptr));
        return min + (rand() % ((max+1) - min));
    }

    void reduceRange(int reduce){
        min -= reduce;
        max -= reduce;
    }

    void print() const{
        std::cout << min << "-" << max;
    }
};


#endif //GAMEPROJECT_RANGE_H
