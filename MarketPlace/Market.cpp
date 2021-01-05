#include "Market.h"

void Market::open(Hero *hero) {
    std::cout << "Opening Market" << std::endl;

    while(true)
    {
        std::cout << "0.Close Market \t 1.Open ItemType Section \t 2.Open Spells Section" << std::endl;

        int choice;
        std::cin >> choice;

        if ( choice == 0 )
        {
            std::cout << "Have a nice day" << std::endl;
            std::cout << "Closing market" << std::endl;
            return;
        }
        else if ( choice == 1 )
        {
            std::cout << "Opening ItemType Section" << std::endl;
            itemSection.open(hero);
        }
        else if (choice == 2)
        {
            std::cout << "Opening Spells Section" << std::endl;
            spellSection.open(hero);
        }
        else
        {
            std::cout << "Invalid Input, try again" << std::endl;
            continue;
        }
    }
}

void Market::addItem(Item *newItem) {
    itemSection.addItem(newItem);
}

void Market::addSpell(Spell *newSpell) {
    spellSection.addSpell(newSpell);
}
