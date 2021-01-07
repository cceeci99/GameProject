
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

    void reduceHealth(int reduce) override;

    void reduceDamage(int reduce);
    void reduceDefence(int reduce);
    void reduceDodge(int reduce);

    void regeneration() override;

    bool avoidAttack() const;

    void activateSpell(EffectType type, int duration){
        spells.activate(type, duration);
    }

    void reduceSpellsRound(){
        spells.reduceRound();
    }

    void checkExpiredSpells() {
        if ( spells.mustDisable(reduce_defence) )
        {
            spells.disable(reduce_defence);
            defence = INIT_DEFENCE;
        }

        if ( spells.mustDisable(reduce_damage) )
        {
            spells.disable(reduce_damage);
            damageRange = INIT_DAMAGE;
        }

        if ( spells.mustDisable(reduce_dodge) )
        {
            spells.disable(reduce_dodge);
            dodge = INIT_DODGE;
        }
    }

};


#endif //GAMEPROJECT_MONSTER_H