#include "Hero.h"

int Hero::getMana() const {
    return mana;
}

int Hero::getMoney() const {
    return money;
}

void Hero::addExperience(int xp) {
    experience += xp;

    if ( experience >= 100 ) {
        levelUp();
    }
}

void Hero::checkInventory() {
    std::cout << "Opening inventory" << std::endl;
    std::cout << "Money: " << money << std::endl;
    inventory.print();

    while (true)
    {
        int pos;
        std::cin >> pos;    // get user input for position of item he want's to use

        if ( pos == 0 )
        {
            std::cout << "Closing inventory" << std::endl;
            return;
        }

        pos--;
        Item* item = inventory.getItem(pos);

        if ( item == nullptr )
        {
            std::cout << "this place is empty choose another item" << std::endl;
            continue;
        }

        if ( item->getType() == armor )
        {
            if (equippedArmor == nullptr )
            {
                equip((Armor*) item);
                inventory.removeItem(pos);
            }
            else
            {
                item = inventory.changeItem(pos, equippedArmor);
                equip((Armor*) item);
            }
        }
        else if ( item->getType() == weapon )
        {
            if (equippedWeapon == nullptr )
            {
                equip((Weapon*)item);
                inventory.removeItem(pos);
            }
            else
            {
                item = inventory.changeItem(pos, equippedWeapon);
                equip((Weapon*)item);
            }
        }
        else
        {
            use((Potion *) item);
            inventory.removeItem(pos);
        }
        inventory.print();

    }
}

void Hero::buyItem(Item *newItem) {
    if ( money >= newItem->getPrice() && level >= newItem->getRequiredLevel() )
    {
        newItem->print();
        std::cout << "Price: " << newItem->getPrice() << std::endl;
        std::cout << "Do you want to buy this item ? Y/N" << std::endl;
        std::string answer;
        std::cin >> answer;

        if ( answer == "Y" || answer == "y" )
        {
            inventory.addItem(newItem);
            money -= newItem->getPrice();
        }
    }
    else
    {
        if ( money < newItem->getPrice() )
            std::cout << "Not enough money to buy the item" << std::endl;
        else
            std::cout << "Level too low to use this item" << std::endl;
    }
}

void Hero::buySpell(Spell *newSpell) {
    if ( money >= newSpell->getPrice() && level >= newSpell->getRequiredLevel() )
    {
        newSpell->print();
        std::cout << "Price: " << newSpell->getPrice() << std::endl;
        std::cout << "Do you want to buy this spell ? Y/N" << std::endl;
        std::string answer;
        std::cin >> answer;

        if ( answer == "Y" || answer == "y" )
        {
            skills.addSpell(newSpell);
            money -= newSpell->getPrice();
        }
    }
    else
    {
        if ( money < newSpell->getPrice() )
            std::cout << "Not enough money to buy the spell" << std::endl;
        else
            std::cout << "Level too low to use this spell" << std::endl;
    }
}

void Hero::sellItem(int pos) {
    Item* item = inventory.getItem(pos);
    item->print();
    std::cout << "Do you want to sell this item? Y/N" << std::endl;
    std::string answer;
    std::cin >> answer;

    if ( answer == "Y" || answer == "y" )
    {
        money += item->getPrice() / 2;
        inventory.removeItem(pos);
    }

}

void Hero::sellSpell(int pos) {
    Spell* spell = skills.getSpell(pos);
    spell->print();
    std::cout << "Do you want to sell this spell? Y/N" << std::endl;
    std::string answer;
    std::cin >> answer;

    if ( answer == "Y" || answer == "y")
    {
        money += spell->getPrice()/2;
        skills.removeSpell(pos);
    }
}

void Hero::equip(Weapon* weapon) {
    equippedWeapon = weapon;
    std::cout << weapon->getName() << " weapon equipped" << std::endl;
}

void Hero::equip(Armor *armor) {
    equippedArmor = armor;
    std::cout << armor->getName() << " armor equipped" << std::endl;
}

void Hero::use(Potion *potion) {
    switch (potion->getAttributeType()) {

        case Health:
            health += potion->getAttribute();
            std::cout << "health + " << potion->getAttribute() << std::endl;
            break;
        case Mana:
            mana += potion->getAttribute();
            std::cout << "mana + " << potion->getAttribute() << std::endl;
            break;
        case Strength:
            strength += potion->getAttribute();
            std::cout << "strength + " << potion->getAttribute() << std::endl;
            break;
        case Dexterity:
            dexterity += potion->getAttribute();
            std::cout << "dexterity + " << potion->getAttribute() << std::endl;
            break;
        case Agility:
            agility += potion->getAttribute();
            std::cout << "agility + " << potion->getAttribute() << std::endl;
            break;
    }
}

void Hero::castSpell() {
    std::cout << "Your acquired skills are:" << std::endl;
    skills.print();

    while (true)
    {
        int pos;
        std::cin >> pos;

        if ( pos == 0 )
            return;

        pos--;

        Spell *spell = skills.getSpell(pos);
        if ( spell == nullptr )
        {
            std::cout << "no available skill on this position" << std::endl;
            continue;
        }

        if (mana < spell->getManaRequired())
        {
            std::cout << "Not enough mana to cast this spell" << std::endl;
        }
        else
        {
            std::cout << "Casting " << spell->getName() << std::endl;
            std::cout << "Effect: " << spell->getEffect() << std::endl;
            std::cout << "Damage: " << spell->cast() << std::endl;

            mana -= spell->getManaRequired();

            return;
        }
    }
}


