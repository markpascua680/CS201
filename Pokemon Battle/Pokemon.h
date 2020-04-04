/* Pokemon.h
   Jay-Mark Pascua
   CS 201
   03/22/2020
   Links files together
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <tuple>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Attack {
    string elementType; // Grass, Fire, Water, etc.
    string category;    // Physical, Special, Status effect, etc.
    double power;       // Base damage of the attack
    int accuracy;       // Chance of not missing attack
    int pp;             // Power Points; how many times it can be used in battle
};

struct Pokemon
{
    string name;
    string type;
    map<string, Attack> moves;
    double hp;
    double atk;
    double def;
    double spAtk;
    double spDef;
    double speed;
};

Pokemon pSelect(int id);

#endif
