
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
    Skills skills;

    int CURRENT_HEALTH;
    int CURRENT_MANA;

    Weapon* equippedWeapon = nullptr;
    Armor* equippedArmor = nullptr;

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
    :LivingCreature(name, START_LEVEL, START_HP), mana(START_MP), money(START_MONEY), experience(START_XP),
    strength(strength), dexterity(dexterity), agility(agility), CURRENT_HEALTH(START_HP), CURRENT_MANA(START_MP){}

    ~Hero() override = default;

    void print() const override = 0;

    virtual void levelUp() = 0;

    void printInventory() const;
    void printSkills() const;

    void setCurrentStats();

    bool avoidAttack() const;

    void reduceHealth(int reduce) override;

    void regenerate() override;

    bool dead() const;

    void revive();

    void earnMoney(int earned);
    void looseMoney();

    void addExperience(int xp);

    void buyItem(Item* newItem);
    void buySpell(Spell* newSpell);

    Item* sellItem(int pos);
    Spell* sellSpell(int pos);

    bool haveSkills() const;        //function that returns true if hero have acquired spells

    int attack() const;

    void castSpell(int& damage, int& effect, int& duration, EffectType& type);

    void usePotion();

    void chooseEquipment();         //function that gives the option to player to choose equipment for it's hero (armor/weapon)

    void checkInventory();

};


#endif //GAMEPROJECT_HERO_H