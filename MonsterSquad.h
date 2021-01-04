#include <iostream>
#include <array>

#include "Creatures/Monsters/Monster.h"
#include "Map/Square/Square.h"

#ifndef GAMEPROJECT_MONSTERSQUAD_H
#define GAMEPROJECT_MONSTERSQUAD_H


class MonsterSquad {

private:

    Monster** team;
    int teammates=0;

public:

    explicit MonsterSquad(int teammates){
        //allocate memory for number of teammates which will be given by the user
        team = new Monster*[teammates];
        this->teammates = teammates;
    }

    ~MonsterSquad(){
        for(int i=0; i<teammates; i++)
            delete team[i];

        delete[] team;
    }

    int getSize() const{
        return teammates;
    }

    void print() const{
        for (int i=0; i<teammates; i++){
            team[i]->print();
        }
    }

    void setMonster(Monster* monster){
        for(int i=0; i<teammates; i++)
        {
            if ( team[i] == nullptr )
            {
                team[i] = monster;
                return;
            }
        }
    }

    Monster* getMonster(int pos) const{
        if ( pos >= teammates )
            return nullptr;

        return team[pos];
    }

    Monster** getTeam() const{
        return team;
    }

    bool wiped() const{
        //
        return true;
    }

    void regeneration(){
        //
        return;
    }



};


#endif //GAMEPROJECT_MONSTERSQUAD_H