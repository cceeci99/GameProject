#include "Hero.h"

Hero::Hero(const std::string &name, int newStrength, int newDexterity, int newAgility) : LivingCreature(name, START_HP, START_LEVEL){
    mana = START_MP;
    money = START_MONEY;
    experience = START_XP;

    strength = newStrength;
    dexterity = newDexterity;
    agility = newAgility;
}

Hero::~Hero() = default;