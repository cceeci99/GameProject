
#ifndef GAMEPROJECT_FIGHT_H
#define GAMEPROJECT_FIGHT_H

#include "Squads/HeroSquad.h"
#include "Squads/MonsterSquad.h"


class Fight {

private:
    HeroSquad* heroes;
    MonsterSquad* enemies;


public:

    Fight(HeroSquad* heroes, MonsterSquad* enemies)
    :heroes(heroes), enemies(enemies){};

    ~Fight() = default;

    void displayStats() const{
        heroes->printStats();
        enemies->print();
    }

    bool isOver() const{
        return (heroes->wiped() || enemies->wiped());
    }

    void battle() {
        std::cout << "Battle Begins..." << std::endl;

        unsigned int round = 1;

        if (round % 2 == 1)
        {

            for (int i=0; i<heroes->getSize(); i++)
            {
                Hero* hero = heroes->getHero(i);
                //hero's turn
                std::cout << "Do you want to make normal attack (o), cast spell(l) or use potion(p)" << std::endl;
                char answer;
                std::cin >> answer;

                int r = (int)random() % enemies->getSize();

                if ( answer == 'o' )
                {
                    Monster* mob = enemies->getMonster(r);
                    int damage = hero->attack();
                    //avoid attack
                    if ( mob->getDodge() > 100 ) {
                        continue;
                    }

                    damage -= mob->getDefence();
                    mob->setHealth(mob->getHealth()-damage);
                }
                else if ( answer == 'l')
                {
                    int damage;
                    int effect;
                    int duration;
                    hero->castSpell(damage, effect, duration);

                    // spell on mob , effect for some rounds...
                }
                else if ( answer == 'p')
                {
                    hero->usePotion();
                }
                else
                {
                    std::cout << "invalid input, try again" << std::endl;
                }
            }

        }
        else
        {
            //monster's turn




        }

        heroes->regeneration();
        enemies->regeneration();
    }

};


#endif //GAMEPROJECT_FIGHT_H
