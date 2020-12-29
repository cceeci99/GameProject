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

    void sellItem(Item* item);

    void sellSpell(Spell* spell);

    void checkInventory();

    void equip(Item* item){
        if (item->getType() == weapon)
            equipedWeapon = item;
        else
            equipedArmor = item;
    }

    void use(Potion* potion){
        switch (potion->getAttributeType()) {

            case Health:
                health += potion->getAttribute();
                break;
            case Mana:
                mana += potion->getAttribute();
                break;
            case Strength:
                strength += potion->getAttribute();
                break;
            case Dexterity:
                dexterity += potion->getAttribute();
                break;
            case Agility:
                agility += potion->getAttribute();
                break;
        }
    }

};



#endif //GAMEPROJECT_HERO_H