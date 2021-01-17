# paths
# MODULES = ../modules
# INCLUDE = ../include

# compiler
CC = g++ 

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CFLAGS =  -Wall -Werror -g

# Αρχεία .o
OBJS = main.o Spells/FireSpell.o Spells/IceSpell.o Spells/LightingSpell.o Spells/Spell.o Items/Armor.o Items/Weapon.o Items/Item.o Items/Potion.o Creatures/LivingCreature.o Creatures/Heroes/Hero.o Creatures/Heroes/Inventory.o Creatures/Heroes/Paladin.o Creatures/Heroes/Skills.o Creatures/Heroes/Sorcerer.o Creatures/Heroes/Warrior.o Creatures/Monsters/Dragon.o Creatures/Monsters/ExoSkeleton.o Creatures/Monsters/Monster.o Creatures/Monsters/Spirit.o MarketPlace/ItemSection.o MarketPlace/Market.o MarketPlace/SpellSection.o Map/Square/Square.o Map/Grid/Grid.o Game.o Fight/Fight.o Squads/HeroSquad.o Squads/MonsterSquad.o Creatures/Monsters/ActiveSpells.o Spells/SpellEffect.o

# Το εκτελέσιμο πρόγραμμα
EXEC = main

# Παράμετροι για δοκιμαστική εκτέλεση
#ARGS1 =
 

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(EXEC) 

valgrind: $(EXEC)
	valgrind ./$(EXEC) -E $(ARGS)

run: $(EXEC)
	./$(EXEC) $(ARGS)