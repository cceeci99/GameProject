
#ifndef GAMEPROJECT_MONSTER_H
#define GAMEPROJECT_MONSTER_H

#include "../LivingCreature.h"
#include "MONSTER_ATTRIBUTES.h"

#include "../../Range/Range.h"
#include "ActiveSpells.h"


enum MonsterType{dragon=1, exoskeleton=2, spirit=3};


class Monster: public LivingCreature {

private:
    const Range INIT_DAMAGE;
    const int INIT_DODGE;
    const int INIT_DEFENCE;

    //each monster must have information for active spells that are used on it
    ActiveSpells spells;

protected:
    //each monster has it's damage range, defence and dodge
    Range damageRange;
    int defence;
    int dodge;

public:

    Monster(const std::string& name, int level, Range range, int defence, int dodge)
    : LivingCreature(name, level, MAX_HP),
    damageRange(range), defence(defence), dodge(dodge),
    INIT_DODGE(dodge), INIT_DEFENCE(defence), INIT_DAMAGE(range){};

    ~Monster() override = default;

    void print() const override = 0;

    int attack() const override = 0;

    void regenerate() override;

    bool avoidAttack() const override;

    void reduceHealth(int reduce) override;
    void reduceDamage(int reduce);
    void reduceDefence(int reduce);
    void reduceDodge(int reduce);

    //functions of monster to deal with active spells used on it
    void activateSpell(EffectType type, int duration);
    void reduceSpellsDuration();
    void checkExpiredSpells();

};


#endif //GAMEPROJECT_MONSTER_H