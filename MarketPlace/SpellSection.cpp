#include "SpellSection.h"

SpellSection::SpellSection() {

    for (int i=0; i<SPELLS_CAPACITY; i++)
    {
        spells[i] = nullptr;
    }
}


SpellSection::~SpellSection() {

    for (int i=0; i<SPELLS_CAPACITY; i++)
    {
        if (spells[i] != nullptr)
        {
            delete spells[i];
        }
    }

    delete[] spells;
}


void SpellSection::print() const {

    for (int i=0; i < SPELLS_CAPACITY; i++)
    {
        if (spells[i] != nullptr)
        {
            std::cout << i+1 << ")";
            spells[i]->print();

            std::cout << "Required Level: " << spells[i]->getRequiredLevel() << std::endl;
            std::cout << "Price: " << spells[i]->getPrice() << std::endl;
        }
    }

    std::cout << std::endl;
}


void SpellSection::open(Hero *hero) {

    while(true)
    {
        std::cout << "Available spells on market:" << std::endl;
        print();

        std::cout << "Your Acquired Skills" << std::endl;
        hero->printSkills();

        std::cout << "0.Close Spells Section \t 1.Buy Spell \t 2.Sell Spell" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice)
        {
            case 0:
                std::cout << "Closing Spell Section" << std::endl;
                return;
            case 1:
                buyOption(hero);
                break;
            case 2:
                sellOption(hero);
                break;
            default:
                std::cout << "Invalid input, try again" << std::endl;
                continue;
        }
    }
}


void SpellSection::buyOption(Hero *hero) {

    while(true)
    {
        std::cout << "Which spell you would like to buy ?" << std::endl;

        int pos;
        std::cin >> pos;

        if (pos == 0)
            return;

        pos--;

        Spell* spell = nullptr;
        spell = getSpell(pos);

        if (spell == nullptr)
        {
            std::cout << "Please choose available spell" << std::endl;
            continue;
        }

        hero->buySpell(spell);


        std::cout << "Your Acquired Skills" << std::endl;
        hero->printSkills();
    }
}


void SpellSection::sellOption(Hero *hero) {

    while(true)
    {
        std::cout << "Which spell from yours you would like to sell ?" << std::endl;

        int pos;
        std::cin >> pos;

        if (pos == 0)
            break;

        pos--;

        Spell* spell = nullptr;
        spell =hero->sellSpell(pos);

        if (spell == nullptr)
        {
            std::cout << "Please choose available spell" << std::endl;
            continue;
        }

        std::cout << "Your Acquired Skills" << std::endl;
        hero->printSkills();
    }
}


void SpellSection::addSpell(Spell *newSpell) {

    if (addedSpells >= SPELLS_CAPACITY)
        return;

    for(int i = 0; i < SPELLS_CAPACITY; i++)
    {
        if (spells[i] == nullptr)
        {
            spells[i] = newSpell;
            addedSpells++;
            return;
        }
    }
}


Spell *SpellSection::getSpell(int pos) {

    if (pos >= SPELLS_CAPACITY)
        return nullptr;

    return spells[pos];
}