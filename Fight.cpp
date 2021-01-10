#include "Fight.h"


bool Fight::begin() {
    return ((random() % 100 + 1) <= 40);
}


bool Fight::isNotOver() const {
    return !(heroes->defeated() || enemies->defeated());
}


void Fight::displayStats() const {
    std::cout << "Stats of Heroes: " << std::endl;
    heroes->print();

    std::cout << "Stats of Monsters: " << std::endl;
    enemies->print();
}


bool Fight::playerTurn() {
    std::cout << "Do you want to display stats?" << std::endl;

    char answer;
    while(true)
    {
        std::cin >> answer;
        if(answer == 'y' || answer == 'Y')
        {
            displayStats();
            break;
        }
        else if (answer =='n' || answer == 'N')
        {
            break;
        }
        else if ( answer == 'q' || answer == 'Q')
        {
            return false;
        }
        else
        {
            std::cout << "Invalid input please try again" << std::endl;
            continue;
        }
    }

    int i=0;
    while (i<heroes->getSize())
    {
        if (enemies->defeated())
            return true;

        Hero* hero = heroes->getHero(i);

        if (hero->dead())
        {
            i++;
            continue;
        }

        std::cout << "Play with " << hero->getName() << std::endl;
        std::cout << "Do you want to choose equipment y/n?" << std::endl;

        std::cin >> answer;
        while ( answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N' && answer != 'q' && answer != 'Q')
        {
            std::cout << "Invalid input please try again" << std::endl;
            std::cin >> answer;
        }

        if ( answer == 'y' || answer == 'Y') {
            hero->chooseEquipment();
        }
        else if (answer == 'q' || answer == 'Q') {
            return false;
        }

        std::cout << "Do you want to make normal attack (o), cast spell(l) or use potion(p)" << std::endl;
        std::cin >> answer;

        if ( answer == 'Q'|| answer == 'q' ) {
            return false;
        }

        while( answer != 'o' && answer != 'l' && answer != 'p' )
        {
            std::cout << "invalid input try again" << std::endl;
            std::cin >> answer; 
        }

        //each hero attacks random monster from the heroes
        int r = (int)random() % enemies->getSize();
        Monster* monster = enemies->getMonster(r);

        if ( monster->avoidAttack() )
        {
            std::cout << monster->getName() << " avoided attack" << std::endl;
            continue;
        }

        if (answer == 'o')
        {
            normalAttack(hero, monster);
        }
        else if (answer == 'l')
        {
            if ( !hero->haveSkills() )
            {
                std::cout << "You don't have any acquired spells" << std::endl;
                continue;
            }
            else
            {
                spellAttack(hero, monster);
            }
        }
        else if (answer == 'p')
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
        if ( heroes->defeated() )
            return;

        Monster* monster = enemies->getMonster(i);

        if (monster->dead())
            continue;

        int r = (int)random() % heroes->getSize();
        Hero* hero = heroes->getHero(r);

        if ( hero->avoidAttack() )
        {
            std::cout << hero->getName() << " avoided attack" << std::endl;
            continue;
        }

        monsterAttack(monster, hero);
    }
}

void Fight::normalAttack(Hero *hero, Monster *monster) {
    int damage = hero->attack();

    std::cout << hero->getName() << " performs normal attack on " << monster->getName() << " damage " << damage << std::endl;

    monster->reduceHealth(damage);

    if (monster->dead()){
        std::cout << "Just killed " << monster->getName() << std::endl;
    }
}

void Fight::spellAttack(Hero *hero, Monster *monster) {
    EffectType type;
    int damage;
    int effect;
    int duration;

    hero->castSpell(damage, effect, duration, type);


    std::cout << hero->getName() << " performs spell on " << monster->getName() << " damage " << damage << std::endl;

    monster->reduceHealth(damage);
    monster->activateSpell(type, duration);

    if ( type == reduce_defence )
    {
        monster->reduceDefence(effect);
        std::cout << "Defence reduced by " << effect << std::endl;
    }
    else if ( type == reduce_dodge )
    {
        monster->reduceDodge(effect);
        std::cout << "Dodge reduced by " << effect << std::endl;
    }
    else if ( type == reduce_damage)
    {
        monster->reduceDamage(effect);
        std::cout << "Damage reduced by " << effect << std::endl;
    }

    if (monster->dead()){
        std::cout << " You just killed " << monster->getName() << std::endl;
    }

}

void Fight::monsterAttack(Monster *monster, Hero *hero) {
    int damage = monster->attack();
    std::cout << monster->getName() << " performs attack on " << hero->getName() << " damage " << damage << std::endl;

    hero->reduceHealth(damage);

    if (hero->dead()) {
        std::cout << hero->getName() << " defeated " << std::endl;
    }
}
