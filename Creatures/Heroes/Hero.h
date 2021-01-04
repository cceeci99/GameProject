#include <iostream>

#include "../LivingCreature.h"

#include "Inventory.h"
#include "Skills.h"

#include "../../Items/Weapon.h"
#include "../../Items/Potion.h"
#include "../../Items/Armor.h"

#ifndef GAMEPROJECT_HERO_H
#define GAMEPROJECT_HERO_H


//use hero Type for player choice of hero
enum HeroType{warrior=1, paladin=2, sorcerer=3};


class Hero: public LivingCreature {

private:
    int money;

    Weapon* equippedWeapon = nullptr;
    Armor* equippedArmor = nullptr;

    Skills skills;
    Inventory inventory;

protected:
    int mana;
    int experience;
    int strength;
    int dexterity;
    int agility;

public:

    Hero(const std::string& name, int strength, int dexterity, int agility)
    :LivingCreature(name, START_LEVEL, START_HP), mana(START_MP), money(START_MONEY), experience(START_XP),
    strength(strength), dexterity(dexterity), agility(agility){}

    ~Hero() override = default;

    void print() const override = 0;
    virtual void levelUp() = 0;

    void addExperience(int xp);

    int getMoney() const;

    void regeneration() override{
        if ( health != 0 ){
            health += 10/100*health;
        }
        mana += mana + 15/100*mana;
    }

    void buyItem(Item* newItem);
    void buySpell(Spell* newSpell);

    Item* sellItem(int pos);
    Spell* sellSpell(int pos);

    void printInventory() const;
    void printSkills() const;

    void checkInventory();

    void equip(Weapon* weapon);
    void equip(Armor* armor);
    void use(Potion* potion);

    int attack() const;
    void castSpell(int& damage, int& effect, int& duration);       //casting spell on monster, spell make some damage on monster and has an effect for some turns
    void usePotion();

};




#endif //GAMEPROJECT_HERO_H