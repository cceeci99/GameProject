#include "Fight.h"


bool Fight::begin() {
    return ((float) (random()/RAND_MAX) > 0.45);
}

bool Fight::isNotOver() const {
    return (heroes->defeated() || enemies->defeated());
}

void Fight::displayStats() const {
    heroes->printStats();
    enemies->print();
}

void Fight::battle(int round) {
    std::cout << "Battle Begins..." << std::endl;

    //hero's turn
    if (round % 2 == 1)
    {
        int i=0;
        while ( i<heroes->getSize() )
        {
            Hero* hero = heroes->getHero(i);

            std::cout << "Do you want to make normal attack (o), cast spell(l) or use potion(p)" << std::endl;
            char answer;
            std::cin >> answer;

            //each hero attacks random monster from the heroes
            int r = (int)random() % enemies->getSize();
            Monster* mob = enemies->getMonster(r);

            if ( answer == 'o' )
            {
                int damage = hero->attack();

                if ( mob->avoidAttack() )
                {
                    i++;
                    continue;
                }

                damage -= mob->getDefence();
                mob->reduceHealth(damage);
            }
            else if ( answer == 'l')
            {
                EffectType type;
                int damage;
                int effect;
                int duration;

                hero->castSpell(damage, effect, duration, type);

                // spell on mob , effect for some rounds...

                damage -= mob->getDefence();
                mob->reduceHealth(damage);

                EffectType tempType = type;
                if ( type == reduce_defence )
                {
                    mob->reduceDefence(effect);
                }
                else if ( type == reduce_dodge )
                {
                    mob->reduceDodge(effect);
                }
                else if ( type == reduce_damage)
                {
                    mob->reduceDamage(effect);
                }

            }
            else if ( answer == 'p')
            {
                hero->drinkPotion();
            }
            else if ( answer == 't')
            {
                std::cout << "Stats of heroes and monsters are:" << std::endl;
                displayStats();
                continue;
            }
            else
            {
                std::cout << "invalid input, try again" << std::endl;
                continue;
            }
            i++;
        }

    }
    //monster's turn
    else
    {
        for (int i=0; i<enemies->getSize(); i++)
        {
            Monster* mob = enemies->getMonster(i);

            int r = (int)random() % heroes->getSize();
            Hero* hero = heroes->getHero(r);

            if ( hero->avoidAttack() )
                continue;

            int damage = mob->attack();
            damage -= hero->getArmorDefence();

            hero->reduceHealth(damage);
        }
    }

    heroes->regeneration();
    enemies->regeneration();
}