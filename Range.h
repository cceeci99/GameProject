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
        srandom(time(nullptr));
        return min + ((int)random() % ((max+1) - min));     //get a random value within the range
    }

    void reduceRange(int reduce){
        min -= reduce;
        max -= reduce;
    }

    void print() const{
        std::cout << min << "-" << max << std::endl;
    }

    static Range getRandomRange(int lowerBound, int upperBound){
        srandom(time(nullptr));
        int min = (int)random() % lowerBound;
        int max = min + ((int)random() % ((upperBound+1) - min));

        Range range(min, max);
        return range;
    }
};

#endif //GAMEPROJECT_RANGE_H