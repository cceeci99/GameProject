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

void Hero::checkInventory() const {
    std::cout << "Hero's inventory: " << std::endl;
    std::cout << "Money: " << money << std::endl;
    inventory.print();

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



void Hero::sellItem(Item *item) {
    item->print();
    std::cout << "Do you want to sell this item? Y/N" << std::endl;
    std::string answer;
    std::cin >> answer;

    if ( answer == "Y" || answer == "y" )
    {
        money += item->getPrice() / 2;
        inventory.removeItem(item);
    }

}

void Hero::sellSpell(Spell *spell) {
    spell->print();
    std::cout << "Do you want to sell this spell? Y/N" << std::endl;
    std::string answer;
    std::cin >> answer;

    if ( answer == "Y" || answer == "y")
    {
        money += spell->getPrice()/2;
        skills.removeSpell(spell);
    }
}
