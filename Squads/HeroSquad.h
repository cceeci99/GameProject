
#ifndef GAMEPROJECT_HEROSQUAD_H
#define GAMEPROJECT_HEROSQUAD_H

#include "../Creatures/Heroes/Hero.h"
#include "../Map/Square/Square.h"


class HeroSquad {

private:

    Hero** squad;
    int teammates=0;

public:

    explicit HeroSquad(int teammates);

    ~HeroSquad();

    int getSize() const;

    void print() const;

    void setHero(Hero* hero);

    Hero* getHero(int pos) const;

    Hero** getSquad() const;

    void move(Square* square);

    bool wiped() const;

    void regeneration();

    void printStats() const;

    void openInventory() {
        for (int i=0; i<teammates; i++){
            std::cout << "Do you want to open inventory for hero: " << squad[i]->getName() << " ? Y/N" << std::endl;

            char answer;
            std::cin >> answer;

            if ( answer == 'Y' || answer == 'y' ) {
                squad[i]->checkInventory();
            }
        }
    }

};


#endif //GAMEPROJECT_HEROSQUAD_H
