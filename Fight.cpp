#include "Fight.h"


bool Fight::begin() {
    return   true;
    //(double) random()/RAND_MAX > 0.45;
}

bool Fight::isNotOver() const {
    return !(heroes->defeated() || enemies->defeated());
}

void Fight::displayStats() const {
    heroes->printStats();
    enemies->print();
}

void Fight::playerTurn() {
    int i=0;
    char answer;
    std::cout << "Do you want to display stats?" << std::endl;
    std::cin >> answer;

    if( answer == 'y' || answer == 'Y' ){
        std::cout << "Stats before fight:" << std::endl;
        displayStats();
    }


    while ( i<heroes->getSize() )
    {
        Hero* hero = heroes->getHero(i);

        char answer;
        std::cout << "Do you want to choose equipment?" << std::endl;
        std::cin >> answer;
        if ( answer == 'Y' || answer == 'y' ) {
            hero->chooseEquipment();
        }

        std::cout << "Do you want to make normal attack (o), cast spell(l) or use potion(p)" << std::endl;
        std::cin >> answer;

        while( answer != 'o' && answer != 'l' && answer != 'p' && answer != 't' )
        {
            std::cout << "invalid input try again" << std::endl;
            std::cin >> answer; 
        }

        //each hero attacks random monster from the heroes
        int r = (int)random() % enemies->getSize();
        Monster* mob = enemies->getMonster(r);

        if ( answer == 'o' )        // normal attack
        {
            int damage = hero->attack();

            std::cout << hero->getName() << " performs normal attack on: " << mob->getName() << std::endl;

            if ( mob->avoidAttack() )
            {
                i++;
                std::cout << mob->getName() << " avoided attack" << std::endl;
                continue;
            }

            mob->reduceHealth(damage);

            if (mob->dead())
                std::cout << "Just killed " << mob->getName() << std::endl;

            mob->print();
        }
        else if ( answer == 'l')   // cast spell
        {
            EffectType type;
            int damage;
            int effect;
            int duration;

            hero->castSpell(damage, effect, duration, type);

            std::cout << hero->getName() << " performs spell on: " << mob->getName() << std::endl;

            mob->reduceHealth(damage);

            mob->activateSpell(type, duration);

            if ( type == reduce_defence ){
                mob->reduceDefence(effect);
            }
            else if ( type == reduce_dodge ){
                mob->reduceDodge(effect);
            }
            else if ( type == reduce_damage){
                mob->reduceDamage(effect);
            }

            if (mob->dead())
                std::cout << "Just killed " << mob->getName() << std::endl;

            mob->print();
        }
        else if ( answer == 'p')
        {
            std::cout << "Choose potion" << std::endl;
            hero->drinkPotion();
        }

        i++;
    }
}

void Fight::enemiesTurn() {
    for (int i=0; i<enemies->getSize(); i++)
    {
        Monster* mob = enemies->getMonster(i);

        int r = (int)random() % heroes->getSize();
        Hero* hero = heroes->getHero(r);

        if ( hero->avoidAttack() ){
            std::cout << hero->getName() << " avoided attack" << std::endl;
            continue;
        }

        std::cout << mob->getName() << " performs attack on: " << hero->getName() << std::endl;

        int damage = mob->attack();
        std::cout << "Damage from monster: " << damage << std::endl;
        hero->reduceHealth(damage);

        if (hero->dead())
            std::cout <<  hero->getName() <<" defeated by: " << mob->getName() << std::endl;

        hero->print();
    }
}