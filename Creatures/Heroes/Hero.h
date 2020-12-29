#include <iostream>
#include <vector>

#include "../LivingCreature.h"
#include "HERO_ATTRIBUTES.h"

#include "../../Items/Item.h"
#include "../../Items/Weapon.h"
#include "../../Spells/Spell.h"
#include "Inventory.h"
#include "Skills.h"
#include "../../Items/Potion.h"

#ifndef GAMEPROJECT_HERO_H
#define GAMEPROJECT_HERO_H


class Hero: public LivingCreature {

private:
    int mana;
    int money;

    Item* equipedWeapon = nullptr;
    Item* equipedArmor = nullptr;

    Skills skills;
    Inventory inventory;

protected:
    int experience;
    int strength;
    int dexterity;
    int agility;

public:
    Hero(const std::string& name, int newStrength, int newDexterity, int newAgility)
    :LivingCreature(name, START_LEVEL, START_HP){
        mana = START_MP;
        money = START_MONEY;
        experience = START_XP;

        strength = newStrength;
        dexterity = newDexterity;
        agility = newAgility;
    }

    ~Hero() override = default;

    int getMana() const;

    int getMoney() const;

    void addExperience(int xp);

    void print() const override = 0;

    virtual void levelUp() = 0;

    void buyItem(Item* newItem);

    void buySpell(Spell* newSpell);

    void sellItem(int pos);

    void sellSpell(int pos);

    void checkInventory();

    void equip(Item* item);

    void use(Potion* potion);

    void castSpell();
};



#endif //GAMEPROJECT_HERO_H