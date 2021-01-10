
#ifndef GAMEPROJECT_MONSTER_H
#define GAMEPROJECT_MONSTER_H

#include "MONSTER_ATTRIBUTES.h"
#include "../LivingCreature.h"
#include "ActiveSpells.h"


enum MonsterType{dragon=1, exoskeleton=2, spirit=3};


class Monster: public LivingCreature {

private:
    const int INIT_DODGE;
    const int INIT_DEFENCE;
    const Range INIT_DAMAGE;

    ActiveSpells spells;

protected:
    Range damageRange;
    int defence;
    int dodge;


public:

    Monster(const std::string& name, int level, Range range, int defence, int dodge)
    :LivingCreature(name, level, START_HP), damageRange(range), defence(defence), spells() ,dodge(dodge), INIT_DODGE(dodge), INIT_DEFENCE(defence), INIT_DAMAGE(range){};

    ~Monster() override = default;

    void print() const override = 0;

    virtual int attack() const = 0;

    bool avoidAttack() const;

    void reduceHealth(int reduce) override;
    void reduceDamage(int reduce);
    void reduceDefence(int reduce);
    void reduceDodge(int reduce);

    bool dead() const;
    void regenerate() override;


    //functions of monster to deal with spells on it
    void activateSpell(EffectType type, int duration);
    void reduceSpellsRound();
    void checkExpiredSpells();

};


#endif //GAMEPROJECT_MONSTER_H