#include "Hero.h"


void Hero::addExperience(int xp) {

    if (level == MAX_LEVEL)
    {
        std::cout << "You reached max level!" << std::endl;
        return;
    }

    experience += xp;

    //experience required for next level
    int nextLevelExperience = 5 * ((level+1)*(level+1)) - (5 * (level+1));


    if (experience >= nextLevelExperience)
    {
        std::cout << "Level UP! Congrats you reached level " << level+1 << std::endl;
        levelUp();
        return;
    }

    std::cout << "  |Current Experience: " << experience << "   Experience for next level: " << nextLevelExperience << "|" << std::endl;

}


void Hero::earnMoney(int gold) {
    money += gold;
}


void Hero::looseMoney() {
    money = money/2;
}


bool Hero::avoidAttack() const {
    int r = (int)random() % 100 +1;

    return (r <= agility);
}


void Hero::reduceHealth(int reduce) {
    if (equippedArmor != nullptr)
    {

        if (reduce <= equippedArmor->getAttribute())
            return;

        health = health - (reduce - equippedArmor->getAttribute());

        if (health < 0)
        {
            health = 0;
        }
    }
    else
    {
        health = health - reduce;

        if ( health < 0 )
        {
            health = 0;
        }
    }
}


void Hero::regenerate() {

    if (health != 0)
    {
        health += (int) (health*(0.1));
        if (health >= 1000)
        {
            health = 1000;
        }
    }

    mana += (int) (mana*(0.1));

    if (mana >= 1000)
    {
        mana = 1000;
    }
}


void Hero::revive() {
    health = MAX_HP / 2;
    mana = MAX_MP / 2;
}


void Hero::buyItem(Item *newItem) {

    if (money >= newItem->getPrice())
    {
        if (level < newItem->getRequiredLevel())
        {
            std::cout << "You haven't reached the required level to buy this item" << std::endl << std::endl;
            return;
        }

        if (inventory.addItem(newItem))
        {
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

    if (money >= newSpell->getPrice())
    {
        if (level < newSpell->getRequiredLevel())
        {
            std::cout << "You haven't reached the required level to buy this spell" << std::endl << std::endl;
            return;
        }

        if (spells.addSpell(newSpell))
        {
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

    if (item != nullptr)
    {
        money += item->getPrice() / 2;
    }

    return item;
}


Spell* Hero::sellSpell(int pos) {

    Spell* spell = spells.removeSpell(pos);

    if (spell != nullptr)
    {
        money += spell->getPrice() / 2;
    }

    return spell;
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

    switch (potion->getAttributeType())
    {

        case Health:
            health += potion->getAttribute();
            std::cout << "health + " << potion->getAttribute() << std::endl;
            if (health >= MAX_HP ) {
                health = MAX_HP;
            }
            break;
        case Mana:
            mana += potion->getAttribute();
            std::cout << "mana + " << potion->getAttribute() << std::endl;
            if (mana >= MAX_MP ) {
                mana = MAX_MP;
            }
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


bool Hero::spellsEmpty() const {
    return spells.empty();
}


void Hero::printInventory() const {
    std::cout << "Money: " << money << std::endl;
    inventory.print();
}


void Hero::printSkills() const {
    spells.print();
}


int Hero::attack() const {

    if (equippedWeapon != nullptr)
    {
        return strength + equippedWeapon->getAttribute();
    }
    else
    {
        return strength;
    }
}


void Hero::castSpell(int& damage, int& effect, int& duration, EffectType& type) {

    std::cout << "Your acquired spells are:" << std::endl;
    spells.print();


    while (true)
    {
        std::cout << "Choose the position of the spell you want to cast" << std::endl;

        int pos;
        std::cin >> pos;

        pos--;

        Spell *spell = spells.getSpell(pos);
        if (spell == nullptr)
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
            damage = (int) (spell->getDamage() + dexterity*0.1);

            if ( damage > spell->getMaxDamage() )
            {
                damage = spell->getMaxDamage();
            }

            type = spell->getEffectType();
            effect = spell->getEffect();
            duration = spell->getDuration();

            std::cout << "Casting " << spell->getName() << std::endl;
            mana = mana - spell->getManaRequired();

            return;
        }
    }
}


bool Hero::usePotion() {

    std::cout << "Choose potion" << std::endl;
    Potion* potion = inventory.choosePotion();

    if (potion != nullptr)
    {
        use(potion);
    }
    else
        return false;

    return true;
}


void Hero::chooseEquipment() {

    if (inventory.empty())
    {
        std::cout << "your inventory is empty" << std::endl;
        return;
    }

    std::cout << "Choose the position of armor you want to equip (0 for none)" << std::endl;
    Armor* arm = inventory.chooseArmor();

    if (arm != nullptr)
    {
        if (equippedArmor != nullptr)
        {
            inventory.changeItem(arm, equippedArmor);
        }
        else
        {
            inventory.removeItem(arm);
        }
        equip(arm);
    }

    std::cout << "Choose the position of weapon you want to equip (0 for none)" << std::endl;
    Weapon* weap = inventory.chooseWeapon();

    if (weap != nullptr)
    {
        if (equippedWeapon != nullptr)
        {
            inventory.changeItem(weap, equippedWeapon);
        }
        else
        {
            inventory.removeItem(weap);
        }
        equip(weap);
    }
}


void Hero::checkInventory() {

    std::cout << "Opening inventory: " << std::endl;

    inventory.print();

    while (true)
    {
        if (inventory.empty())
        {
            std::cout << "No items in your inventory" << std::endl;
            return;
        }

        std::cout << "Choose the position of the item you want to equip/use or 0 to close inventory" << std::endl;

        int pos;
        std::cin >> pos;    // get user input for position of item he want's to use

        if (pos == 0)
        {
            std::cout << "Closing inventory" << std::endl;
            return;
        }

        pos--;
        Item* item = inventory.getItem(pos);

        if (item == nullptr)
        {
            std::cout << "this place is empty choose another item" << std::endl;
            continue;
        }

        if (item->getType() == armor)
        {
            if (equippedArmor == nullptr)
            {
                equip((Armor *) item);
                inventory.removeItem(pos);
            }
            else
            {
                item = inventory.changeItem(pos, equippedArmor);
                equip((Armor *) item);
            }
        }
        else if (item->getType() == weapon)
        {
            if (equippedWeapon == nullptr)
            {
                equip((Weapon *) item);
                inventory.removeItem(pos);
            }
            else
            {
                item = inventory.changeItem(pos, equippedWeapon);
                equip((Weapon *) item);
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