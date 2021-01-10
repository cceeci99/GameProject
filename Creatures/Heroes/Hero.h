
#ifndef GAMEPROJECT_HERO_H
#define GAMEPROJECT_HERO_H

#include "../LivingCreature.h"

#include "Inventory.h"
#include "Skills.h"

#include "../../Items/Weapon.h"
#include "../../Items/Potion.h"
#include "../../Items/Armor.h"
#include "../../Spells/SpellEffect.h"


//use hero Type for player choice of hero
enum HeroType{warrior=1, paladin=2, sorcerer=3};


class Hero: public LivingCreature {

private:
    int CURRENT_HEALTH;
    int CURRENT_MANA;

    int money;

    Weapon* equippedWeapon = nullptr;
    Armor* equippedArmor = nullptr;

    Inventory inventory;
    Skills skills;


    //uses of items from inventory
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

    //battle methods
    void setCurrentStats();
    bool avoidAttack() const;
    void reduceHealth(int reduce) override;
    void regenerate() override;
    bool dead() const;
    void revive();

    //after battle methods
    void earnMoney(int earned);
    void looseMoney();
    void addExperience(int xp);

    //transactions that are made by hero in market
    void buyItem(Item* newItem);
    void buySpell(Spell* newSpell);
    Item* sellItem(int pos);
    Spell* sellSpell(int pos);

    //methods for the player
    bool haveSkills() const;
    int attack() const;
    void castSpell(int& damage, int& effect, int& duration, EffectType& type);
    void usePotion();
    void chooseEquipment();
    void checkInventory();

};


#endif //GAMEPROJECT_HERO_H