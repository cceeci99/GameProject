# compiler
CC = g++

CFLAGS = -std=c++11
CCFLAGS = -Wall -Werror -g

# Αρχεία .o
OBJS = Range/Range.o Spells/Spell.o Spells/FireSpell.o Spells/IceSpell.o Spells/LightingSpell.o  Spells/SpellEffect.o Items/Item.o Items/Armor.o Items/Weapon.o Items/Potion.o Creatures/LivingCreature.o Creatures/Monsters/Monster.o Creatures/Monsters/Spirit.o Creatures/Monsters/Dragon.o Creatures/Monsters/ExoSkeleton.o Creatures/Monsters/ActiveSpells.o Creatures/Heroes/Hero.o Creatures/Heroes/Warrior.o Creatures/Heroes/Paladin.o Creatures/Heroes/Sorcerer.o Creatures/Heroes/Inventory.o Creatures/Heroes/Skills.o Map/Grid/Grid.o Map/Square/Square.o MarketPlace/Market.o MarketPlace/ItemSection.o  MarketPlace/SpellSection.o Squads/HeroSquad.o Squads/MonsterSquad.o Fight/Fight.o Game.o main.o

EXEC = game

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS)  -o $(EXEC) $(OBJS) $(CCFLAGS)

Range/Range.o: Range/Range.cpp
	$(CC) $(CFLAGS) -c -o Range/Range.o Range/Range.cpp

Spells/Spell.o: Spells/Spell.cpp
	$(CC) $(CFLAGS) -c -o Spells/Spell.o Spells/Spell.cpp

Spells/FireSpell.o: Spells/FireSpell.cpp
	$(CC) $(CFLAGS) -c -o Spells/FireSpell.o Spells/FireSpell.cpp

Spells/IceSpell.o: Spells/IceSpell.cpp
	$(CC) $(CFLAGS) -c -o Spells/IceSpell.o  Spells/IceSpell.cpp

Spells/LightingSpell.o: Spells/LightingSpell.cpp
	$(CC) $(CFLAGS) -c -o Spells/LightingSpell.o Spells/LightingSpell.cpp

Spells/SpellEffect.o: Spells/SpellEffect.cpp
	$(CC) $(CFLAGS) -c -o Spells/SpellEffect.o Spells/SpellEffect.cpp

Items/Item.o: Items/Item.cpp
	$(CC) $(CFLAGS) -c -o Items/Item.o Items/Item.cpp

Items/Armor.o: Items/Armor.cpp
	$(CC) $(CFLAGS) -c -o Items/Armor.o Items/Armor.cpp

Items/Weapon.o: Items/Weapon.cpp
	$(CC) $(CFLAGS) -c -o Items/Weapon.o Items/Weapon.cpp

Items/Potion.o: Items/Potion.cpp
	$(CC) $(CFLAGS) -c -o Items/Potion.o Items/Potion.cpp

Creatures/LivingCreature.o: Creatures/LivingCreature.cpp
	$(CC) $(CFLAGS) -c -o Creatures/LivingCreature.o Creatures/LivingCreature.cpp

Creatures/Monsters/Monster.o: Creatures/Monsters/Monster.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Monsters/Monster.o Creatures/Monsters/Monster.cpp

Creatures/Monsters/Spirit.o: Creatures/Monsters/Spirit.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Monsters/Spirit.o Creatures/Monsters/Spirit.cpp

Creatures/Monsters/Dragon.o: Creatures/Monsters/Dragon.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Monsters/Dragon.o Creatures/Monsters/Dragon.cpp

Creatures/Monsters/ExoSkeleton.o: Creatures/Monsters/ExoSkeleton.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Monsters/ExoSkeleton.o Creatures/Monsters/ExoSkeleton.cpp

Creatures/Monsters/ActiveSpells.o: Creatures/Monsters/ActiveSpells.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Monsters/ActiveSpells.o Creatures/Monsters/ActiveSpells.cpp

Creatures/Heroes/Hero.o: Creatures/Heroes/Hero.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Heroes/Hero.o Creatures/Heroes/Hero.cpp

Creatures/Heroes/Warrior.o: Creatures/Heroes/Warrior.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Heroes/Warrior.o Creatures/Heroes/Warrior.cpp

Creatures/Heroes/Paladin.o: Creatures/Heroes/Paladin.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Heroes/Paladin.o Creatures/Heroes/Paladin.cpp

Creatures/Heroes/Sorcerer.o: Creatures/Heroes/Sorcerer.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Heroes/Sorcerer.o Creatures/Heroes/Sorcerer.cpp

Creatures/Heroes/Inventory.o: Creatures/Heroes/Inventory.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Heroes/Inventory.o Creatures/Heroes/Inventory.cpp

Creatures/Heroes/AcquiredSpells.o: Creatures/Heroes/AcquiredSpells.cpp
	$(CC) $(CFLAGS) -c -o Creatures/Heroes/AcquiredSpells.o Creatures/Heroes/AcquiredSpells.cpp

Map/Grid/Grid.o: Map/Grid/Grid.cpp
	$(CC) $(CFLAGS) -c -o Map/Grid/Grid.o Map/Grid/Grid.cpp

Map/Square/Square.o: Map/Square/Square.cpp
	$(CC) $(CFLAGS) -c -o Map/Square/Square.o Map/Square/Square.cpp

MarketPlace/Market.o: MarketPlace/Market.cpp
	$(CC) $(CFLAGS) -c -o MarketPlace/Market.o MarketPlace/Market.cpp

MarketPlace/ItemSection.o: MarketPlace/ItemSection.cpp
	$(CC) $(CFLAGS) -c -o MarketPlace/ItemSection.o MarketPlace/ItemSection.cpp

MarketPlace/SpellSection.o: MarketPlace/SpellSection.cpp
	$(CC) $(CFLAGS) -c -o MarketPlace/SpellSection.o MarketPlace/SpellSection.cpp

#Squads
Squads/HeroSquad.o: Squads/HeroSquad.cpp
	$(CC) $(CFLAGS) -c -o Squads/HeroSquad.o Squads/HeroSquad.cpp

Squads/MonsterSquad.o: Squads/MonsterSquad.cpp
	$(CC) $(CFLAGS) -c -o Squads/MonsterSquad.o Squads/MonsterSquad.cpp

Fight/Fight.o: Fight/Fight.cpp
	$(CC) $(CFLAGS) -c -o Fight/Fight.o Fight/Fight.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f $(EXEC) $(OBJS)

valgrind: $(EXEC)
	valgrind ./$(EXEC) -E $(ARGS)

run: $(EXEC)
	./$(EXEC) $(ARGS)