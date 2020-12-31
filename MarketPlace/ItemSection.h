#include <iostream>
#include "../Creatures/Heroes/Hero.h"

#ifndef GAMEPROJECT_ITEMSECTION_H
#define GAMEPROJECT_ITEMSECTION_H

#define ITEMS_CAPACITY 50


class ItemSection {

private:
    int addedItems = 0;
    Item** items = new Item*[ITEMS_CAPACITY];

public:

    ~ItemSection(){
        delete[] items;
    }

    void print() const{
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

    void buyOption(Hero* hero) {
        while (true) {
            std::cout << "Which item you would like to buy ?" << std::endl;

            int pos;
            std::cin >> pos;

            if (pos == 0)
                break;

            pos--;

            Item *item = removeItem(pos);

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

    void sellOption(Hero* hero){
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

            addItem(item);

            std::cout << "Item Section:" << std::endl;
            print();
            std::cout << "Your inventory: " << std::endl;
            hero->printInventory();

        }
    }

    void open(Hero* hero){
        while (true)
        {
            std::cout << "Available items:" << std::endl;
            print();
            std::cout << "Your Inventory: " << std::endl;
            hero->printInventory();

            std::cout << "0.Close Items Section \t 1.Buy Item \t 2.Sell Item " << std::endl;

            int choice;
            std::cin >> choice;

            if (choice == 0)
            {
                std::cout << "Closing Items Section" << std::endl;
                return;
            }
            else if (choice == 1)
            {
                buyOption(hero);
            }
            else if (choice == 2)
            {
                sellOption(hero);
            }
            else
            {
                std::cout << "Invalid input, try again" << std::endl;
                continue;
            }
        }
    }

    void addItem(Item* newItem){
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
    Item* removeItem(int pos) {
        if ( pos >= ITEMS_CAPACITY )
            return nullptr;

        Item* temp = items[pos];
        items[pos] = nullptr;
        addedItems--;

        return temp;
    }

};


#endif //GAMEPROJECT_ITEMSECTION_H
