#include "Fight.h"


Fight::Fight(HeroSquad *heroes, MonsterSquad *enemies) :heroes(heroes), enemies(enemies){
    std::cout << "Fight Begins..." << std::endl;
}


bool Fight::begin() {
    return ((random() % 100 + 1) <= 60);
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

    int i = 0;

    while (i < heroes->getSize())
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

        std::cout << "Do you want to make normal attack (o), cast spell(l), use potion(p), display stats (c) or choose equipment(e)" << std::endl;
        char answer;
        std::cin >> answer;

        while(answer != NORMAL_ATTACK && answer != CAST_SPELL && answer != USE_POTION && answer != CHOOSE_EQUIPMENT && answer != SHOW_STATS  && answer != QUIT_ && answer != QUIT)
        {
            std::cout << "invalid input try again" << std::endl;
            std::cin >> answer; 
        }


        if (answer == NORMAL_ATTACK)
        {
            Monster* monster = attackRandomMonster();
            if (monster != nullptr)
            {
                attack(hero, monster);
            }
        }
        else if (answer == CAST_SPELL)
        {
            if (hero->spellsEmpty())
            {
                std::cout << "You don't have any acquired spells choose another option" << std::endl;
                continue;
            }
            else
            {
                Monster* monster = attackRandomMonster();
                if (monster != nullptr)
                {
                    spellAttack(hero, monster);
                }
            }
        }
        else if (answer == USE_POTION)
        {
            if(!hero->usePotion())
            {
                std::cout << "You don't have any potions available choose another option" << std::endl;
                continue;
            }
        }
        else if (answer == SHOW_STATS)     //if player choose to display stats or choose equipment for some hero continue with the same hero until he make any attack or choose potion
        {
            displayStats();
            continue;
        }
        else if (answer == CHOOSE_EQUIPMENT)
        {
            hero->chooseEquipment();
            continue;
        }
        else if (answer == QUIT || answer == QUIT_)
        {
            return false;
        }

        i++;
    }

    return true;
}


void Fight::enemiesTurn() {

    for (int i = 0; i < enemies->getSize(); i++)
    {
        if (heroes->defeated())
            return;

        Monster* monster = enemies->getMonster(i);

        if (monster->dead())
            continue;

        Hero* hero = attackRandomHero();
        if (hero != nullptr)
        {
            attack(monster, hero);
        }
    }
}


Monster *Fight::attackRandomMonster() const {
    int r = (int) random() % enemies->getSize();
    Monster* monster = enemies->getMonster(r);

    //if some monster chosen for attack is dead try another one
    while (monster->dead())
    {
        r = (int) random() % enemies->getSize();
        monster = enemies->getMonster(r);
    }

    if (monster->avoidAttack())
    {
        std::cout << monster->getName() << " avoided attack" << std::endl;
        return nullptr;
    }

    return monster;
}


Hero *Fight::attackRandomHero() const {
    int r = (int) random() % heroes->getSize();
    Hero* hero = heroes->getHero(r);

    //if random hero that is chosen for attack is dead choose another one
    while (hero->dead())
    {
        r = (int) random() % heroes->getSize();
        hero = heroes->getHero(r);
    }

    if (hero->avoidAttack())
    {
        std::cout << hero->getName() << " avoided attack" << std::endl;
        return nullptr;
    }

    return hero;
}


void Fight::attack(LivingCreature *attacker, LivingCreature *victim) {
    int damage = attacker->attack();
    std::cout << attacker->getName() << " makes " << damage << " damage on " << victim->getName() << std::endl;

    victim->reduceHealth(damage);

    if (victim->dead())
    {
        std::cout << victim->getName() << " defeated " << std::endl;
        return;
    }

    std::cout << victim->getName() << "'s health: " << victim->getHealth() << std::endl;
}


void Fight::spellAttack(Hero *hero, Monster *monster) {

    EffectType effect;
    int damage;
    int reduce;
    int duration;

    hero->castSpell(damage, reduce, duration, effect);

    std::cout << hero->getName() << " makes " << damage << " damage on " << monster->getName() << std::endl;

    monster->activateSpell(effect, duration);

    if (effect == reduce_defence)
    {
        monster->reduceDefence(reduce);
        std::cout << monster->getName() <<"'s Defence reduced by " << reduce << std::endl;
    }
    else if (effect == reduce_dodge)
    {
        monster->reduceDodge(reduce);
        std::cout << monster->getName() << "'s Dodge reduced by " << reduce << std::endl;
    }
    else if (effect== reduce_damage)
    {
        monster->reduceDamage(reduce);
        std::cout << monster->getName() << "'s Damage reduced by " << reduce << std::endl;
    }

    monster->reduceHealth(damage);

    if (monster->dead())
    {
        std::cout << " You just killed " << monster->getName() << std::endl;
        return;
    }

    std::cout << monster->getName() << "'s life: " << monster->getHealth() << std::endl;
}