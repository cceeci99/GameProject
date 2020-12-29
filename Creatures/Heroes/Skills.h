#include <iostream>
#include <vector>
#include <string>
#include "../../Spells/Spell.h"

#ifndef GAMEPROJECT_SKILLS_H
#define GAMEPROJECT_SKILLS_H


class Skills {
private:
    std::vector<Spell*> spells;

public:
    ~Skills(){
        spells.clear();
    }

    void addSpell(Spell* newSpell){
        spells.push_back(newSpell);
    }

    void removeSpell(Spell* spell){
        for (Spell* s: spells)
        {
            if ( s == spell ){
                s = nullptr;
            }
        }
    }

    void print() const{
        int k=1;
        for(Spell* s: spells)
        {
            if ( s != nullptr )
            {
                std::cout << k << ")";
                s->print();
            }
        }
    }
};


#endif //GAMEPROJECT_SKILLS_H
