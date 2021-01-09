#include "Fight.h"


bool Fight::begin() {
    return ((random() % 100 + 1) <= 40);
}


bool Fight::isNotOver() const {
    return !(heroes->defeated() || enemies->defeated());
}


void Fight::displayStats() const {
    heroes->print();
    enemies->print();
}


bool Fight::playerTurn() {
    int i=0;
    char answer;
    std::cout << "Do you want to display stats?" << std::endl;
    std::cin >> answer;

    if( answer == 'y' || answer == 'Y' )
    {
        std::cout << "Stats::" << std::endl;
        displayStats();
    }
    else if ( answer == 'q' || answer == 'Q')
    {
        return false;
    }


    while ( i<heroes->getSize() )
    {
        Hero* hero = heroes->getHero(i);

        if (hero->dead())
        {
            i++;
            continue;
        }

        std::cout << "Play with " << hero->getName() << std::endl;

        std::cout << "Do you want to choose equipment?" << std::endl;
        std::cin >> answer;
        if ( answer == 'Y' || answer == 'y' ) {
            hero->chooseEquipment();
        }
        else if ( answer == 'Q' || answer == 'q' ){
            return false;
        }


        std::cout << "Do you want to make normal attack (o), cast spell(l) or use potion(p)" << std::endl;
        std::cin >> answer;

        if ( answer == 'Q'|| answer == 'q' )
            return false;

        while( answer != 'o' && answer != 'l' && answer != 'p' )
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
                std::cout << mob->getName() << " avoided attack" << std::endl;
                i++;
                continue;
            }

            mob->reduceHealth(damage);

            if (mob->dead()) {
                std::cout << "Just killed " << mob->getName() << std::endl;
            }

            mob->print();
        }
        else if ( answer == 'l')   // cast spell
        {
            EffectType type;
            int damage;
            int effect;
            int duration;

            if (!hero->castSpell(damage, effect, duration, type))
                continue;


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

            if (mob->dead()) {
                std::cout << "Just killed " << mob->getName() << std::endl;
            }

            mob->print();
        }
        else
        {
            hero->usePotion();
        }

        i++;
    }

    return true;
}


void Fight::enemiesTurn() {
    for (int i=0; i<enemies->getSize(); i++)
    {
        Monster* mob = enemies->getMonster(i);

        if (mob->dead()){
            continue;
        }

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