
#ifndef GAMEPROJECT_MONSTERSQUAD_H
#define GAMEPROJECT_MONSTERSQUAD_H

#include "../Creatures/Monsters/Monster.h"


class MonsterSquad {

private:

    Monster** monsters;
    int numberOfMonsters=0;

public:

    explicit MonsterSquad(int n){
        monsters = new Monster*[n];
        for (int i=0; i<n; i++)
        {
            monsters[i] = nullptr;
        }
        numberOfMonsters = n;
    }

    ~MonsterSquad(){
        std::cout << "Deleting monsters" << std::endl;
        for(int i=0; i < numberOfMonsters; i++)
        {
             if ( monsters[i] != nullptr )
             {
                 std::cout << "deleting " << monsters[i]->getName() << std::endl;
                 delete monsters[i];
             }
        }

        delete[] monsters;
    }

    void print() const;

    int getSize() const;

    Monster* getMonster(int pos) const;
    void setMonster(Monster* monster);

    bool defeated() const;
    void regeneration();

    void unchargeActiveSpells();

};


#endif //GAMEPROJECT_MONSTERSQUAD_H