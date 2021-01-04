
#ifndef GAMEPROJECT_POTION_H
#define GAMEPROJECT_POTION_H

#include "Item.h"
#include "../Creatures/Heroes/HERO_ATTRIBUTES.h"


class Potion: public Item {

private:
    Attribute attribute;
    std::string attributeType;
    const int enhancement;

public:

    Potion(const std::string& name, int price, int level, Attribute attribute, int enhancement, Items type = potion)
    :Item(name, price, level, type), attribute(attribute) , enhancement(enhancement){
        switch (attribute) {

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

    Attribute getAttributeType() const;

    int getAttribute() const override;

};


#endif //GAMEPROJECT_POTION_H
