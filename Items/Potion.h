
#ifndef GAMEPROJECT_POTION_H
#define GAMEPROJECT_POTION_H

#include "Item.h"
#include "../Creatures/Heroes/HERO_ATTRIBUTES.h"


class Potion: public Item {

private:
    //each potion has some attribute, an enhancement value for this attribute, and a string for the type of attribute
    Attribute attribute;
    std::string attributeType;
    const int enhancement;

public:

    Potion(const std::string& name, int price, int level, int enhancement, Attribute attribute)
    :Item(name, price, level, potion), attribute(attribute) , enhancement(enhancement){

        //attributes of heroes are given from enum Attribute in HERO_ATTRIBUTES.h
        switch (attribute)
        {
            case Health:
                attributeType = "Health";
                break;
            case Mana:
                attributeType = "Mana";
                break;
            case Strength:
                attributeType = "Strength";
                break;
            case Dexterity:
                attributeType = "Dexterity";
                break;
            case Agility:
                attributeType = "Agility";
                break;
            default:
                break;
        }
    };

    ~Potion() override = default;

    void print() const override;

    int getAttribute() const override;

    Attribute getAttributeType() const;

};


#endif //GAMEPROJECT_POTION_H