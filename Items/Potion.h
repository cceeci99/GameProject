#include "Item.h"
#include "../Creatures/Heroes/HERO_ATTRIBUTES.h"

#ifndef GAMEPROJECT_POTION_H
#define GAMEPROJECT_POTION_H



class Potion: public Item {
private:
    Attribute attribute;
    std::string attributeType;
    const int enhancement;
    bool used = false;

public:
    Potion(const std::string& name, int price, int level, Attribute attribute, int enhancement, Items type = potion): Item(name, price, level, type), attribute(attribute) , enhancement(enhancement){
        switch (attribute) {
            case Health:
                attributeType = "Health";
            case Mana:
                attributeType = "Mana";
                break;
            case Experience:
                attributeType = "Experience";
                break;
            case Money:
                attributeType = "Money";
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
        }
    };

    ~Potion() override = default;

    bool isUsed() const;

    void use();

    void print() const override;

    int getAttribute() const override;

};


#endif //GAMEPROJECT_POTION_H
