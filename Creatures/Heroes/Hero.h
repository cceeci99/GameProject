
#ifndef GAMEPROJECT_HERO_H
#define GAMEPROJECT_HERO_H

#include "../LivingCreature.h"

#include "Inventory.h"
#include "Skills.h"


enum HeroType{warrior=1, paladin=2, sorcerer=3};


class Hero: public LivingCreature {

private:
    int money;

    Inventory inventory;
    Skills skills;          //by skills, we mean the acquired spells of a hero

    Weapon* equippedWeapon = nullptr;
    Armor* equippedArmor = nullptr;

    //functions equip of armor/weapon and use of potion are private, and only class hero has access of them and calls them when it's needed
    void equip(Weapon* weapon);
    void equip(Armor* armor);
    void use(Potion* potion);


protected:
    int mana;
    int experience;

    int strength;
    int dexterity;
    int agility;


public:

    Hero(const std::string& name, int strength, int dexterity, int agility)
    : LivingCreature(name, START_LEVEL, MAX_HP), mana(MAX_MP), money(START_MONEY), experience(START_XP),
      strength(strength), dexterity(dexterity), agility(agility){}

    ~Hero() override = default;

    void print() const override = 0;

    virtual void levelUp() = 0;

    void addExperience(int xp);

    void earnMoney(int money);
    void looseMoney();

    //methods used when hero is at market so he can see his stuffs and spells
    void printInventory() const;
    void printSkills() const;

    bool avoidAttack() const;

    void reduceHealth(int reduce) override;

    void regenerate() override;

    bool dead() const;

    void revive();

    void buyItem(Item* newItem);
    void buySpell(Spell* newSpell);

    Item* sellItem(int pos);
    Spell* sellSpell(int pos);

    int attack() const;

    //function that returns true if hero have acquired spells
    bool haveSkills() const;

    //while casting spell we must return it's damage, effect type of effect and it's duration those are given with parameters by reference
    void castSpell(int& damage, int& effect, int& duration, EffectType& type);

    //function that shows available potions hero haves and returns false if they aren't any potions
    bool usePotion();

    //function that gives the option to player to choose equipment for it's hero (armor/weapon)
    void chooseEquipment();

    void checkInventory();

};


#endif //GAMEPROJECT_HERO_H