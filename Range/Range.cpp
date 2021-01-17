#include "Range.h"

void Range::print() const {
    std::cout << min << "-" << max << std::endl;
}

int Range::getValue() const {
    return min + ((int)random() % ((max+1) - min));     //return random value within the range
}

int Range::getMax() const {
    return max;
}

void Range::reduceRange(int reduce) {
    //reduce both bounds , checking that no one will be below zero
    min -= reduce;
    max -= reduce;

    if ( min < 0 )
        min = 0;

    if ( max < 0 )
        max = 0;
}