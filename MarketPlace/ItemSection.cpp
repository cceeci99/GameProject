#include "ItemSection.h"


void ItemSection::print() const {
    for (int i=0; i < ITEMS_CAPACITY; i++)
    {
        if (items[i] != nullptr)
        {
            std::cout << i+1 << ")";
            items[i]->print();
            std::cout << "Price: " <<items[i]->getPrice() << std::endl;
        }
    }
    std::cout << std::endl;
}


void ItemSection::open(Hero *hero) {
    while (true) {
        std::cout << "Available items:" << std::endl;
        print();
        std::cout << "Your Inventory: " << std::endl;
        hero->printInventory();

        std::cout << "0.Close ItemType Section \t 1.Buy Item \t 2.Sell Item " << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Closing ItemType Section" << std::endl;
            return;
        } else if (choice == 1) {
            buyOption(hero);
        } else if (choice == 2) {
            sellOption(hero);
        } else {
            std::cout << "Invalid input, try again" << std::endl;
            continue;
        }
    }
}


void ItemSection::buyOption(Hero *hero) {
    while (true) {
        std::cout << "Which item you would like to buy ?" << std::endl;

        int pos;
        std::cin >> pos;

        if (pos == 0)
            break;

        pos--;

        Item *item = getItem(pos);

        if (item == nullptr) {
            std::cout << "Please choose available item" << std::endl;
            continue;
        }

        hero->buyItem(item);

        std::cout << "Available items:" << std::endl;
        print();
        std::cout << "Your Inventory: " << std::endl;
        hero->printInventory();
    }
}


void ItemSection::sellOption(Hero *hero) const {
    while (true)
    {
        std::cout << "Which item from yours you want to sell ?" << std::endl;

        int pos;
        std::cin >> pos;

        if ( pos == 0 )
            break;

        pos--;

        Item* item = hero->sellItem(pos);

        if ( item == nullptr )
        {
            std::cout << "Please choose available item" << std::endl;
            continue;
        }

        std::cout << "Item Section:" << std::endl;
        print();
        std::cout << "Your inventory: " << std::endl;
        hero->printInventory();

    }
}


void ItemSection::addItem(Item *newItem) {
    if ( addedItems >= ITEMS_CAPACITY )
        return;

    for(int i=0; i < ITEMS_CAPACITY; i++)
    {
        if ( items[i] == nullptr )
        {
            items[i] = newItem;
            addedItems++;
            return;
        }
    }
}


Item *ItemSection::getItem(int pos) {
    if ( pos >= ITEMS_CAPACITY )
        return nullptr;

    return items[pos];
}