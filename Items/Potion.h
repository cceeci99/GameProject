#include "Item.h"

#ifndef GAMEPROJECT_POTION_H
#define GAMEPROJECT_POTION_H


class Potion: public Item {
private:
    const int enhancement;

public:
    Potion(const std::string& name, double price, int level, int enhancement):Item(name, price, level), enhancement(enhancement){};
    ~Potion() override = default;

    int getEnhancement() const{
        return enhancement;
    }
    void print() const override{
        std::cout << "Potion " << getName();
    }
};


#endif //GAMEPROJECT_POTION_H
