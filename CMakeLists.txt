cmake_minimum_required(VERSION 3.17)
project(GameProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(GameProject main.cpp Items/Item.h Items/Weapon.h Items/Armor.h Items/Potion.h Spells/Spell.h Spells/IceSpell.h)