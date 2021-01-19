
#ifndef GAMEPROJECT_GAME_H
#define GAMEPROJECT_GAME_H

#include <vector>

#include "Map/Grid/Grid.h"
#include "MarketPlace/Market.h"

#include "Squads/HeroSquad.h"
#include "Squads/MonsterSquad.h"
#include "Fight/Fight.h"

#include "Creatures/Heroes/Warrior.h"
#include "Creatures/Heroes/Paladin.h"
#include "Creatures/Heroes/Sorcerer.h"

#include "Creatures/Monsters/Dragon.h"
#include "Creatures/Monsters/ExoSkeleton.h"
#include "Creatures/Monsters/Spirit.h"

#include "Spells/FireSpell.h"
#include "Spells/IceSpell.h"
#include "Spells/LightingSpell.h"

#include "KEYBOARD_SYMBOLS.h"

#define MAP_SIZE 8
#define MAX_TEAMMATES 3



class Game {

private:

    Grid* map = nullptr;

    Market* marketPlace = nullptr;

    HeroSquad* squad = nullptr;

    void createHeroes();

    MonsterSquad* createEnemies();

    Market* createMarket();

    //methods returning bool value are used in case player quit game at any point of the game

    bool playerMove(Square* currentPos, unsigned int& x1, unsigned int& y1);

    bool enterMarket();
    bool enterCommon();

    void victory(int monstersDefeated);
    void defeat();

    static std::string getUnusedName(std::vector<std::string>& usedNames, std::string* names);

public:

    Game();

    ~Game();

    void play();

};


#endif //GAMEPROJECT_GAME_H