#include <iostream>
#include <vector>

#include "../LivingCreature.h"
#include "HERO_ATTRIBUTES.h"

#include "../../Items/Item.h"
#include "../../Items/Weapon.h"

#ifndef GAMEPROJECT_HERO_H
#define GAMEPROJECT_HERO_H


class Hero: public LivingCreature {
private:
    int mana;
    int money;

    std::vector<Item*> inventory;

protected:
    int experience;
    int strength;
    int dexterity;
    int agility;

public:
    Hero(const std::string& name, int newStrength, int newDexterity, int newAgility) : LivingCreature(name, START_HP, START_LEVEL){
        mana = START_MP;
        money = START_MONEY;
        experience = START_XP;

        strength = newStrength;
        dexterity = newDexterity;
        agility = newAgility;
    }

    ~Hero() override = 0;

    int getMana() const{
        return mana;
    }
    int getMoney() const{
        return money;
    }

    void addExperience(int xp){
        experience += xp;

        if ( experience >= 100 )
            levelUp();
    }

    void print() const override = 0;
    void levelUp() override = 0;

    void buy(Item* item){
        if ( money >= item->getPrice() && level >= item->getRequiredLevel() )
            inventory.push_back(item);
    }
};



#endif //GAMEPROJECT_HERO_H