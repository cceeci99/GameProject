#include "Market.h"


void Market::open(Hero *hero) {

    std::cout << "Opening Market..." << std::endl;

    while(true)
    {
        std::cout << "Choose 0 or 1 or 2" << std::endl;
        std::cout << "0.Close Market \t 1.Open Items Section \t 2.Open Spells Section" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice)
        {
            case 0:
                std::cout << "Thank you, have a nice day! Closing market..." << std::endl;
                return;
            case 1:
                std::cout << "Opening Items Section" << std::endl;
                itemSection.open(hero);
                break;
            case 2:
                std::cout << "Opening Spells Section" << std::endl;
                spellSection.open(hero);
                break;
            default:
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