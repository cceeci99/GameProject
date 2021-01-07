#include "Hero.h"

int Hero::getMoney() const {
    return money;
}


void Hero::printInventory() const {
    std::cout << "Your Money: " << money << std::endl;
    inventory.print();
    std::cout << std::endl;
}


void Hero::printSkills() const {
    skills.print();
    std::cout << std::endl;
}

void Hero::reduceHealth(int reduce) {
    if ( equippedArmor != nullptr )
    {

        if ( reduce <= equippedArmor->getAttribute() )
            return;

        health = health - (reduce - equippedArmor->getAttribute());

        if ( health < 0 ) {
            health = 0;
        }
    }
    else{
        health = health - reduce;

        if ( health < 0 ){
            health = 0;
        }
    }
}


bool Hero::dead() const {
    return health==0;
}


void Hero::earnMoney(int earned) {
    money += earned;
}


void Hero::looseMoney() {
    money = money/2;
}


void Hero::addExperience(int xp) {
    experience += xp;
    //experience required for next level
    int nextLevel = 500 * (level ^ 2) - (500 * level);

    if ( experience >= nextLevel ) {
        levelUp();
    }
}


void Hero::setCurrentStats() {
    CURRENT_HEALTH = health;
    CURRENT_MANA = mana;
}


bool Hero::avoidAttack() const {
//    int r = (int)random() % 100 +1;

//    return (r <= agility);
    return false;
}


void Hero::regeneration() {
    if ( health != 0 ){
//        health += 10/100*health;
        health+= 50;
        if ( health >= 1000 )
            health = 1000;
    }
//    mana += mana + 15/100*mana;
    mana += 50;
    if ( mana >= 1000 )
        mana = 1000;
}


void Hero::revive() {
    health = CURRENT_HEALTH/2;
    mana = CURRENT_MANA/2;
}


void Hero::buyItem(Item *newItem) {
    if ( money >= newItem->getPrice() )
    {
        if (inventory.addItem(newItem)) {
            money -= newItem->getPrice();
        }
    }
    else
    {
        std::cout << "Not enough money to buy the item" << std::endl;
        return;
    }
}


void Hero::buySpell(Spell *newSpell) {
    if ( money >= newSpell->getPrice() )
    {
        if (skills.addSpell(newSpell)) {
            money -= newSpell->getPrice();
        }
    }
    else
    {
            std::cout << "Not enough money to buy the spell" << std::endl;
            return;
    }
}


Item* Hero::sellItem(int pos) {
    Item* item = inventory.removeItem(pos);

    if ( item != nullptr ) {
        money += item->getPrice() / 2;
    }

    return item;
}


Spell* Hero::sellSpell(int pos) {
    Spell* spell = skills.removeSpell(pos);

    if ( spell != nullptr ) {
        money += spell->getPrice() / 2;
    }

    return spell;
}


void Hero::equipWeapon(Weapon* weapon) {
    equippedWeapon = weapon;
    std::cout << weapon->getName() << " weapon equipped" << std::endl;
}


void Hero::equipArmor(Armor *armor) {
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


int Hero::attack() const {
    if ( equippedWeapon != nullptr ) {
        return strength + equippedWeapon->getAttribute();
    }
    else{
        return strength;
    }
}


void Hero::castSpell(int& damage, int& effect, int& duration, EffectType& type) {
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
            damage = spell->cast();
            effect = spell->getEffect();
            type = spell->getEffectType();
            duration = spell->getDuration();

            std::cout << "Casting " << spell->getName() << std::endl;
            std::cout << "damage: " <<  damage <<std::endl;

            mana -= spell->getManaRequired();

            return;
        }
    }
}


void Hero::usePotion() {
    std::cout << "Choose potion" << std::endl;
    Potion* potion = inventory.choosePotion();

    if ( potion != nullptr ) {
        use(potion);
    }
}


void Hero::chooseEquipment() {
    std::cout << "Choose armor" << std::endl;
    Armor* arm = inventory.chooseArmor();

    if ( arm != nullptr )
    {
        if ( equippedArmor != nullptr ){
            inventory.changeItem(arm, equippedArmor);
        }
        else{
            inventory.removeItem(arm);
        }
        equipArmor(arm);
    }

    std::cout << "Choose weapon" << std::endl;
    Weapon* weap = inventory.chooseWeapon();

    if ( weap != nullptr )
    {
        if ( equippedWeapon != nullptr ){
            inventory.changeItem(weap, equippedWeapon);
        }
        else{
            inventory.removeItem(weap);
        }
        equipWeapon(weap);
    }

}


void Hero::checkInventory() {
    std::cout << "Opening inventory" << std::endl;
    std::cout << "Money: " << money << std::endl;
    inventory.print();

    while (true)
    {
        if ( inventory.empty() ) {
            std::cout << "No items in your inventory" << std::endl;
        }

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

        if ( item->getRequiredLevel() > level )
        {
            std::cout << "Your level is too low to use this item" << std::endl;
            continue;
        }

        if ( item->getType() == armor )
        {
            if (equippedArmor == nullptr )
            {
                equipArmor((Armor *) item);
                inventory.removeItem(pos);
            }
            else
            {
                item = inventory.changeItem(pos, equippedArmor);
                equipArmor((Armor *) item);
            }
        }
        else if ( item->getType() == weapon )
        {
            if (equippedWeapon == nullptr )
            {
                equipWeapon((Weapon *) item);
                inventory.removeItem(pos);
            }
            else
            {
                item = inventory.changeItem(pos, equippedWeapon);
                equipWeapon((Weapon *) item);
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